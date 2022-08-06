#ifndef SCOREFILE_H
#define SCOREFILE_H

#include<vector>
#include<string>
#include<utility>

class ScoreFile {

    private:

    std::vector<std::pair<std::string, float>> ScoresSheet;
    std::string UserName;
    float score;
    std::pair<std::string, float> HighestScoredUser;

    void ReadScoreFromFile();
    void ArrangeScores();
    void HighestScore();

    public:

    auto GetScoresSheet() const {
        return &ScoresSheet;
    }

    auto GetHighestScoredUser() const {
        return &HighestScoredUser;
    }

    ScoreFile();
    ~ScoreFile();

    void WriteScoreToFile(float);
};

#endif