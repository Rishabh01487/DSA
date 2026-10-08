class Solution {
public:
    bool hasCycle(int course, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[course] == 1)
            return true;

        if (visited[course] == 2)
            return false;

        visited[course] = 1;

        for (int nextCourse : graph[course]) {
            if (hasCycle(nextCourse, graph, visited))
                return true;
        }

        visited[course] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<int> visited(numCourses, 0);

        for (int course = 0; course < numCourses; course++) {
            if (hasCycle(course, graph, visited))
                return false;
        }

        return true;
    }
};