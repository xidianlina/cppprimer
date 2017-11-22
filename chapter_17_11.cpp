#include <iostream>
#include <bitset>
#include <string>

using size = std::size_t;
template <size N> 
class QuizResponses {
public:
	QuizResponses() = default;
	QuizResponses(const std::string& s) : answers(s) {}

	void answer(size n, bool v) { answers.set(n - 1, v); }

	size score(const QuizResponses& correct)
	{
		return (this->answers ^ correct.answers).flip().count() * 1.0 / N * 100;
	}

private:
	std::bitset<N> answers;
};

int main()
{
	QuizResponses<10> simple_quiz_answers("1100110101");

	QuizResponses<100> complicated_quiz_answers;
	complicated_quiz_answers.answer(1, true);
	complicated_quiz_answers.answer(2, false);
	complicated_quiz_answers.answer(3, true);

	QuizResponses<10> simple_quiz_correct("1010101010");
	std::cout << simple_quiz_answers.score(simple_quiz_correct) << std::endl;
}