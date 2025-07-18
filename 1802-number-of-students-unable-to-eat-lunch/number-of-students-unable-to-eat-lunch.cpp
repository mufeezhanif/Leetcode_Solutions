class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int extraCount = 0;
        int s_index = 0;
        int i = 0;
        while (s_index < sandwiches.size() &&
               find(students.begin(), students.end(), sandwiches[s_index]) !=
                   students.end()) {
            if (students[i] == sandwiches[s_index]) {
                s_index++;
                students[i] = -1;
            } else {
                students.push_back(students[i]);
                students[i] = -1;
            }
            extraCount++;
            i++;
        }
        return students.size() - extraCount;
    }
};