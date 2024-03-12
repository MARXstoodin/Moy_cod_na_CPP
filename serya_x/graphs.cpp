#include <iostream>
#include <vector>

int bfs
(
	std::vector<bool>& colour,
	std::vector<std::vector<int>>& graph,
	int start,
	int end
)
{
	std::vector<int> toVisit;
	
	for(int it = 0; it < graph[start].size(); ++it)
	{
		colour[graph[start][it]] = true;
		toVisit.push_back(graph[start][it]);
	}
	
	std::vector<int> swapArray;
	int depth = 1;
	
	while(!toVisit.empty())
	{
		for(int i = 0; i < toVisit.size(); ++i)
		{
			int currNode = toVisit[i];
			if(currNode == end)
				return depth;
			for(int j = 0; j < graph[currNode].size(); j++)
			{
				if(colour[graph[currNode][j]]) 
					continue;
			
				swapArray.push_back(graph[currNode][j]);
				colour[graph[currNode][j]] = true;
			}
		}
	}
	depth++;
	swap(toVisit, swapArray);
	return 0;
}

int main()
{
	int n;
	std::vector<bool> colours(100);
	std::vector<std::vector<int>> vc(100);
	std::cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		vc[x].push_back(y);
		vc[y].push_back(x);
	}
	
	std::cout<<bfs(colours,vc,1,2);
	return 0;
}
