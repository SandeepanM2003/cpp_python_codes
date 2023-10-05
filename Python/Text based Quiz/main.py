import random
import time

def run_quiz(questions):
    print("Welcome to the Quiz Game!")
    player_name = input("Enter your name: ")
    print(f"Hello, {player_name}! Let's start the quiz.")

    random.shuffle(questions)
    score = 0
    timer_per_question = 15  # Set the timer for each question (in seconds)

    for question in questions:
        print(question['question'])
        for i, option in enumerate(question['options'], start=1):
            print(f"{i}. {option}")

        start_time = time.time()
        user_answer = input(f"Your answer (1-{len(question['options'])}): ")
        end_time = time.time()
        elapsed_time = end_time - start_time

        if elapsed_time > timer_per_question:
            print("Time's up! You ran out of time.")
        else:
            try:
                user_answer = int(user_answer)
                correct_answer_index = question['options'].index(question['correct_answer']) + 1

                if user_answer == correct_answer_index:
                    print("Correct! Well done.")
                    score += 1
                else:
                    print(f"Oops! The correct answer was {correct_answer_index}: {question['correct_answer']}")
            except ValueError:
                print("Invalid input. Please enter a number.")

    print(f"Quiz completed, {player_name}!")
    print(f"Your score: {score} out of {len(questions)}")

if __name__ == "__main__":
    # Sample quiz questions (add more questions as needed)
    quiz_questions = [
        {
            'question': 'What is the capital of France?',
            'options': ['London', 'Paris', 'Berlin', 'Madrid'],
            'correct_answer': 'Paris'
        },
        {
            'question': 'Which planet is known as the Red Planet?',
            'options': ['Mars', 'Venus', 'Jupiter', 'Saturn'],
            'correct_answer': 'Mars'
        },
        {
            'question': 'What is the largest mammal in the world?',
            'options': ['Elephant', 'Blue Whale', 'Giraffe', 'Hippopotamus'],
            'correct_answer': 'Blue Whale'
        }
    ]

    run_quiz(quiz_questions)
