# Amortized Efficiency of List Update Rules

Notes for reading/writing assignment due for [HW_3_Self-Adjusting](../HW_3_Self-Adjusting/)

## Introduction

The paper will discuss these two algorithms

* "move-to-front"
    * rule for maintaining an unsorted linear list representing a set
* "least-recently-used"
    * replacement rule for reducing page faults in a two-level page memory

Amortization means averaging the runtime of an algorithm over a worst-case sequence of operations.

Taking the average runtime over the worst case senarios gives much more information than testing an average case.  It's what is most likely to happen.

It tells you the an average worst that your algorithm can perform.  I don't think anybody is gonna complain if your algorthim happens to run faster.

Worst-Bounds are typically overly pessimistic.

* No algorithm, online or not, can beat `move-to-front` by more than a constant factor, on any sequence of operations.

* `move-half-way-to-front` rule satisfies a similar bound but with a constant factor of four instead of two.

## Self Organizing Lists

The dictionary problem: Maintain a set of items under an intermixed sequence of the following three kinds of operations

* access(i): Locate item `i` in the set.

* insert(i): Insert item `i` into the set.

* delete(i): Delete item `i` from the set.

`n` will denote the maximum number of items ever in the set at one time

while `m` will denote the total number of operations.

The initial set will typically be assumed empty.

### Unordered List

Accessing an item

1. Scan for item (Front to back) until locating the item

Inserting an item

1. Scan the entire list to verify the value does not already exist.
2. Insert value at the end of the list.

Deleting an Item

1. Scan the list (front-to-back) to find the item.
2. If item is found, remove it.

It may be beneficial to exchange pairs of consecutive items to speed up future operations.

Separate the two costs by `comparisons` and `number of exchanges`.

* The relative cost of an exchange vs the comparison depends on the implementation of the list.

* Accessing or deleting the `i`th item in the list requires `i` comparisons.

* Inserting a new item takes `i + 1` comparisons, where i is the size of the list before the insertion. (We charge a comparison for locating the end of the list)

Amortized bounds: 

Becomes important when dealing with different types of operations.

* Assign an amortized cost for each operation.
* such that you preserve the sum of thost costs.

e.g. the sum of all operations of the amortized cost of that operation, and compare to the sum of the actual cost of the operations.  Amortized should be bigger.

* We care about the total runtime of the algorithm rather than each individual operation. - [Erik Demaine MIT Courseware Youtube](https://www.youtube.com/watch?v=3MpzavN3Mco)

* Linear time to do an insertion is bad :(

* Aggregate method: Total cost of `k` operations / `k`. Gives us the amortized cost per operation.

## Goal: Make total cost of a sequence as small as possible

* Move-to-front (MF). After accessing or inserting an item, move it to the front of the list, without changing the relative order of the other items.

* Transpose (T). After accessing or inserting an item, exchange it with the immediately preceding item.

* Frequency count (FC). Maintain a frequency count for each item, initially zero. Increase the count of an item by one whenever it is inserted or accessed; reduce its count to zero when it is deleted. Maintain the list so that the items are in non-increasing order by frequency count.

  * Track the number of occurances of an item

* Nash and Weber found `move-to-front` to perform much better in practice due to it reaching it's asymptotic behavior quicker for an initially randomized list.

* Bently and McGoech studied the amortized complexity of list update rules and found: Compareed the optimum static algorithm `decreasing frequency` (DF).  DF minimizes the total access cost if compared to algorithms that do not rearange the elements.

    * `Transpose` is inferior to `move-to-front`
    * `move-to-front` is competative with `frequency count` but sometimes better.

## Paging

* Two-level memory devided into pages of fixed uniform size.
* `n` number of pages of fast memory
* each operation is an access that specifies a page of information.
* If the page is in fast memory, the access costs nothing.
* If the page is in slow memory we must swap it for a page in fast memory, at the cost of one page fault.
* The goal is to minimize the number of page faults for a given sequence of accesses.

Paging Rules

* Least-recently-used (LRU): When a page fault occurs, replace the page whose most recent access was earliest.
* First-in, first-out (FIFO): Replace the page that has been in fast memory the longest.
* Last-in, first-out (LIFO): Replace the page most recently moved to fast memory.
* Least-frequently-used (LFU): Replace the page that has been accessed the least.
* Longest-forward-distance (MIN): Replace the page whose next access is the latest.

LFU === move to front list updating

LFU === frequency count

* On-line algorithms require no knowledge of future accesses.

## Other notes

* Dictionary application

* Move to front rule for list updating is considered best practice for updating lists.

* Online vs Offline algorithms?? 
    * The article didn't explain the definition of online vs offline algorithms in its initial use which initially cause me some confusion, but once it defined the terms I was able to understand more of the article.

* Measuring differences between `move-to-front`, `transposed`, and `frequency count` rules.

* At times the paper became difficult to understand due to notations and symbols I had not yet become aquainted with.

* Some of the dense logical proofs were also difficult to follow while reading through the first couple times due to heavy use of initialisms and references.

I found that I had to suplement quite a bit to even understand the article.

* 