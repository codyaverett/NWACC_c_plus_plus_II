How would you determine that an algorithm is more performant.

Benchmarking works fine for a specific hardware piece.

How do we determine

Big O Notation - As I increase the inputs, how does the complexity of the

Elements vs Time

Rate of growth relative to how many elements are being processed.

What could I expect the growth to be over time.

We will have to determine the Big O notation for each of our functions and justify our decisions.

## Linear Search

- Iterates over every item of a list

e.g.

List of 3 items.
Best case, find answer in first element, 1st element
Worst case, answer does not exist, nth element

Average Case `n/2`. Looking through about half of them.

Big O would be `O(N)`

## Selection Sort

Itterate over a list, find smallest/largest and puts value in the front.

Only way to do this would be to start performing this would be a linear search

1. Find smalls or largest `O(n)`

2. Complete until no more elements `O(n^2)`

The growth is quadratic.

## Binary Search

Works on a sorted list.

Find middle point of list.

Relative ordering... If you find it, you are done, but if you don't find it you divide and conquer once again.

Growth would be `O(log N) for the search, but you have to consider that you'd also have to sort the data first.

The most significant Notation would be the search Big O notation which was `O(n^2)` (selection sort for example)

## Logarithms

The inverse of an exponent.
