#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;


enum class TaskStatus {
	NEW, IN_PROGRESS, TESTING, DONE
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return personTasks.at(person);
	}

	int GetNTasks(const string& person) {
		int n = 0;
		for (auto& [key, value]: personTasks[person]){
			n+=value;
		}
		return n;
	}

	void AddNewTask(const string& person) {
		++personTasks[person][TaskStatus::NEW];
	}

// 	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, 
// 					int task_count) {
// 		int iterSize = min(task_count, GetNTasks(person));
// 		TasksInfo before = personTasks[person];
// 		TasksInfo untouched = personTasks[person];
// 		TasksInfo updated = personTasks[person];

// 		int curr_diff = 0;

// 		if (iterSize > before[TaskStatus::NEW]) {
// 							cout<<"***************";

// 			updated[TaskStatus::NEW] = 0;
// 			untouched[TaskStatus::NEW] = 0;
// 			personTasks[person][TaskStatus::NEW] = 0;

// 			curr_diff = before[TaskStatus::NEW];
// 			iterSize-= curr_diff;
// 			updated[TaskStatus::IN_PROGRESS] += curr_diff;
// 			personTasks[person][TaskStatus::IN_PROGRESS] =curr_diff;


// 			if (iterSize > before[TaskStatus::IN_PROGRESS]) {
// 				// personTasks[person][TaskStatus::IN_PROGRESS] = 0;
// 				// curr_diff = before[TaskStatus::IN_PROGRESS];
// 				// iterSize-= curr_diff;
// 				// personTasks[person][TaskStatus::IN_PROGRESS] += curr_diff;
// 				cout<<"***************";
// 				cout<<personTasks[person][TaskStatus::IN_PROGRESS]<<" **** "<<iterSize;

// 				updated[TaskStatus::IN_PROGRESS] = 0;
// 				untouched[TaskStatus::IN_PROGRESS] = 0;
// 				personTasks[person][TaskStatus::IN_PROGRESS] = 0;

// 				curr_diff = before[TaskStatus::IN_PROGRESS];
// 				iterSize-= curr_diff;
// 				updated[TaskStatus::TESTING] += curr_diff;
// 				personTasks[person][TaskStatus::TESTING] +=curr_diff;


// 				if (iterSize > before[TaskStatus::TESTING]) {

// 					updated[TaskStatus::TESTING] = 0;
// 					untouched[TaskStatus::TESTING] = 0;
// 					personTasks[person][TaskStatus::TESTING] = 0;

// 					curr_diff = before[TaskStatus::TESTING];
// 					iterSize-= curr_diff;
// 					updated[TaskStatus::DONE] += curr_diff;
// 					personTasks[person][TaskStatus::DONE] +=curr_diff;

// 				// personTasks[person][TaskStatus::TESTING] = 0;
// 				// curr_diff = before[TaskStatus::TESTING];
// 				// iterSize-= curr_diff;
// 				// personTasks[person][TaskStatus::TESTING] += curr_diff;
// 				// return tie(personTasks[person], before);
// 				}


// 				else {
// 				// personTasks[person][TaskStatus::TESTING] -= iterSize;
// 				// personTasks[person][TaskStatus::DONE] += iterSize;
				
// 					untouched[TaskStatus::TESTING] -= iterSize;
// 					updated[TaskStatus::DONE] += iterSize;
// 					personTasks[person][TaskStatus::TESTING] = updated[TaskStatus::TESTING]+untouched[TaskStatus::TESTING];
					
// 					// personTasks[person][TaskStatus::DONE] += iterSize;


// 				// // return tie(personTasks[person], before);
// 				}

// 			}
// 			else {
// 			// updated[TaskStatus::IN_PROGRESS] = 0;
// 				cout<<"***************";
// 				cout<<personTasks[person][TaskStatus::IN_PROGRESS]<<" **** "<<iterSize;
// 				untouched[TaskStatus::IN_PROGRESS] = personTasks[person][TaskStatus::IN_PROGRESS]-iterSize;
// 				updated[TaskStatus::TESTING] = personTasks[person][TaskStatus::IN_PROGRESS]+iterSize;
// 				personTasks[person][TaskStatus::IN_PROGRESS] = updated[TaskStatus::IN_PROGRESS]+untouched[TaskStatus::IN_PROGRESS];
			
// // return tie(personTasks[person], before);
// 			}
// 		}
// 		else {
// 							cout<<"***************";

// 			updated[TaskStatus::NEW] = 0;
// 			untouched[TaskStatus::NEW] -= iterSize;
// 			personTasks[person][TaskStatus::NEW] = updated[TaskStatus::NEW]+untouched[TaskStatus::NEW];
// 			updated[TaskStatus::IN_PROGRESS] += iterSize;
// 			// personTasks[person][TaskStatus::IN_PROGRESS] += iterSize;

// 			// return tie(personTasks[person], before);
// 		}
// 		return tie(updated, untouched);
	
// 		// for (int i=0; i<iterSize; ++i) {
// 		// 	personTasks[person][i]
// 		// }
// 	}


	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count) {

		TasksInfo all, updated, untouched;
		int n = min(task_count, GetNTasks(person));
		int diff, minim;

		for (auto& tasks:personTasks[person]) {

			switch(tasks.first) {

				case TaskStatus::NEW: {

					diff = n-tasks.second;
					minim = min(n, tasks.second);

					updated[TaskStatus::IN_PROGRESS] += minim;
					all[TaskStatus::IN_PROGRESS] += minim;					
					
					if (diff<0){
						untouched[TaskStatus::NEW] += -diff;
						all[TaskStatus::NEW] += -diff;
						diff = 0;
					}	
					break;			
				}

				case TaskStatus::IN_PROGRESS: {
					if (tasks.second > 0) {
						minim = min(diff, tasks.second);
						diff -= tasks.second;

						updated[TaskStatus::TESTING] += minim;
						all[TaskStatus::TESTING] += minim;					
						
						if (diff<0){
							untouched[TaskStatus::IN_PROGRESS] += -diff;
							all[TaskStatus::IN_PROGRESS] += -diff;
							}	
						}	
						break;	
				}

				case TaskStatus::TESTING: {
					if (tasks.second > 0) {
						minim = min(diff, tasks.second);
						diff -= tasks.second;

						updated[TaskStatus::DONE] += minim;
						all[TaskStatus::DONE] += minim;					
						
						if (diff<0){
							untouched[TaskStatus::TESTING] += -diff;
							all[TaskStatus::TESTING] += -diff;
							}	
						}
					break;	
				}

				default: {
					if (tasks.second>0) {
						all[TaskStatus::DONE] += tasks.second;
					}	
					break;
				}
			}
			
		}
		personTasks[person] = all;
		return tie(updated, untouched);
	}








private:
	map<string, TasksInfo> personTasks;
};



void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}




int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
