#include <iostream>
using namespace std;

class Points
{
private:
    double score; // To hold the numeric score
public:
    Points()
    {
        score = 0.0;
    }
    Points(double s)
    {
        score = s;
    }
    void setScore(double s)
    {
        score = s;
    }
    double getScore() const
    {
        return score;
    }
    char getLetter() const;
};
char Points::getLetter() const
{
    char letter;
    if (score > 89)
        letter = 'A';
    else if (score > 79)
        letter = 'B';
    else if (score > 69)
        letter = 'C';
    else if (score > 59)
        letter = 'D';
    else
        letter = 'F';
    return letter;
}

class Essay : public Points
{
private:
    double grammar;
    double spelling;
    double correctLength;
    double content;

public:
    Essay() : grammar(0.0), spelling(0.0), correctLength(0.0), content(0.0) {}
    Essay(double g, double s, double cl, double c) : grammar(g), spelling(s), correctLength(cl), content(c)
    {
        calculatescore();
    }
    void calculatescore()
    {
        double totalScore = (grammar * 0.3) + (spelling * 0.2) + (correctLength * 0.2) + (content * 0.3);
        setScore(totalScore);
    }
    void setGrammar(double g)
    {
        grammar = g;
    }
    void setSpelling(double s)
    {
        spelling = s;
    }
    void setCorrectLength(double cl)
    {
        correctLength = cl;
    }
    void setContent(double c)
    {
        content = c;
    }
};

int main()
{
    double g;
    double s;
    double cl;
    double c;

    cout << "***Entering Essay Score***" << '\n';
    cout << "--------------------------" << '\n';
    cout << "Please enter Grammar score (0-100): ";
    cin >> g;
    cout << "Please enter spelling score (0-100): ";
    cin >> s;
    cout << "Please enter Correct Length score (0-100): ";
    cin >> cl;
    cout << "Please enter Content score (0-100): ";
    cin >> c;

    Essay myEssay(g, s, cl, c);

    cout << "Total Score: " << myEssay.getScore() << endl;
    cout << "Letter Grade: " << myEssay.getLetter() << endl;

    return 0;
}