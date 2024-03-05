#include<functional>
#include<vector>
#include<utility>
#include<thread>
#include<windows.h>
#include<chrono>

class Controllers
{
	public:
		Controllers()
		{
			is_running = 0;
		}
		
		~Controllers(){}
		
		void AddEvent(char key, std::function<void()> event)
		{
			std::pair<char, std::function<void()>> task(key, event);
			tasks.push_back(task);
		}
		
		void Run()
		{
			is_running = 1;
			for(auto & task : tasks)
			{
				std::thread* worker = CreateWorker(task);
				workers.push_back(worker);
				
			}
			
			for(auto & worker : workers)
			{
				worker->join();
			}
		}
		
		void Stop()
		{
			is_running = 0;
		}
		
	private:
		int is_running;
		std::vector<std::pair<char, std::function<void()>>> tasks;
		std::vector<std::thread*> workers;
		
		std::thread* CreateWorker(std::pair<char, std::function<void()>> task)
		{
			std::thread* new_worker = new std::thread([task, this]()
			{
				while(this->is_running){
					if(GetKeyState(task.first) & 0x8000)
					{
						task.second();
						std::this_thread::sleep_for(std::chrono::milliseconds(150));
					}
				}
			});
			return new_worker;
		}
};
