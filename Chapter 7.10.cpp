//EC: Chapter 7 Question 10 - Driver's license Exam

//This program should grade a users quiz answers and display if the user
//passed the wxam or not. If the user gets 15 or more questions correct then
//They should get a message that says they passed. Then the number of both 
//Correctly and incorrectly answered questions should be displayed along with
//The question numbers the user got incorrect.

//Input-A string of 20 letters ranging from A-D
//Output-User should see if they passed or failed along with the number of
//questions they got right and wrong, and which question numbers they got wrong


#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

//Defining test answers so they can be placed into a vector
int A = 1;
int B = 2;
int C = 3;
int D = 4;

//These are the correct answers that the user is trying to get
vector<int> testAnswers{ A, D, B, B, C, B, A, B, C, D, A, C, D, B, D, C, C, A, D, B};


//*The user should input their 20 quiz answers[A,B,C,D]
vector<int> avgTestScore(int score);

void test();
int main()
{
	test();
    cout << avgTestScore(B, D, B, B, C, B, A, B, C, D, A, C, D, B, D, C, C, A, D, B);
}


//QUESTION: I am getting mixed up on what belongs where i.e. what my template
//should be doing that my correctAnswers() shouldn't be

//*Template
int gradeAnswers() {
	int i = 0;
	while (i < 20) {
		...score[i]...
			i = i + 1;
	}
	return score[i];
}
//*The Program should count amount of correct answers from 1-20
int j = 0;
//For every correct answer, J should add +1 and at the end, the fina; value
//of J should be the user's score
int correctAnswers() {
	if (avgTestScore[j] == testAnswers[j]) {
		j = j + 1;
	}else{
		if (avgTestScore[j] != testAnswers[j])
			j = j + 0;
	}
	cout << "Correct answers: " << j;
}
//*Program should determin how many incorrect answers by subtracting correct
// answers from 20
//Since incorrect + correct answers = 20, all we have to do is subtract the
//amount right from 20 to get the amount wrong
int incorrectAnswers() {
	int wrong = 20 - j;
	cout << "Incorrect answers: " << wrong;
}

//*Program should display results wether user passed or failed[15-20]
int testResults() {
	if (j >= 15) {
		cout << "You Passed!" << endl;
	}else{
		if (j < 15)
			cout << "You Failed, Better Luck Next Time!" << endl;
}
//*Program should display quantity of correct and incerrect answers
//*Program should display which question numbers user got incorrect


//QUESTION: Since I need to display multiple results from user input 
//(correct, incorrect, & pass/no pass) I don't know how to assert those three
//things all at once
void test() {
	assert(avgTestScore(A, B, C) && testAnswers(A, B, C) ==3);
	assert(avgTestScore(A, B, C) && testAnswers(C, B, A) == 1);
	assert(avgTestScore() && testAnswers(A, B, C) == 0);
	assert(avgTestScore(A, B) && testAnswers(A, B, C) == 2);

		
}
