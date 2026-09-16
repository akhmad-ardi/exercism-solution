#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result;
    for (int i = 0; i < student_scores.size(); ++i) {
        result.push_back(static_cast<int>(student_scores[i]));
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    std::vector<int> result;
    for (int i = 0; i < student_scores.size(); i++) {
        int student_score = static_cast<int>(student_scores[i]);
        if (student_score <= 40) {
            result.push_back(student_score);
        }
    }
    return result.size();
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int highest_to_threshold{highest_score - 40};
    int range_score{highest_to_threshold / 4};

    std::array<int, 4> result = {41, 0, 0, 0};
    for (int i = 1; i < std::size(result); i++) {
        result[i] = result[i - 1] + range_score;
    }
    
    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result;

    for (int i = 0; i < student_scores.size(); i++) {
        std::string ranking = std::to_string(i + 1);
        std::string student_name = student_names[i];
        std::string student_score = std::to_string(student_scores[i]);
        result.push_back(ranking + ". " + student_name + ": " + student_score);
    }
    
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    std::string result{""};

    for (int i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) {
            result = student_names[i];
            break;
        }
    }
    
    return result;
}
