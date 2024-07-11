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
        calculatescore();
    }
    void setSpelling(double s)
    {
        spelling = s;
        calculatescore();
    }
    void setCorrectLength(double cl)
    {
        correctLength = cl;
        calculatescore();
    }
    void setContent(double c)
    {
        content = c;
        calculatescore();
    }
};
1222222222222333333

    int
    main()
{
    // Create an Essay object
    Essay myEssay(28.0, 18.0, 17.0, 29.0);

    // Output the scores and letter grade
    cout << "Total Score: " << myEssay.getScore() << endl;
    cout << "Letter Grade: " << myEssay.getLetter() << endl;

    return 0;
}