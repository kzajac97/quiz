# quiz

Simple command line quiz in C++

## questions

There are three types of questions

* single
* multiple
* fill

They must saved in .txt file with following pattern

```
    #
    question: question?:
    type: multiple
    answers: A, B, C, D
    correct: A,B
```

### Single Choice Question

Mark one answer as correct and choose it as number in range [1, 4] while running the program.
If is was correct answer you get +1 point.

### multiple Choice Question

Choose from 2 to 4 answers in range [1, 4] in data file write them with spaces and commas.
While running the program type them as:

```
1,2,3
```

If all are correct you get +1 point.

### Fill In Question

In data file leave answers as blank place, and type in correct text as correct answer.
While running the program type them as string, if input and correct strings match exactly you get +1 point.
