# push_swap
**Not a sorting algorithm (really not)**

This project is introduced like it was a sorting algorithm.
<br>
You have two stack A and B. The stack A is fulled with unordered integers and your goal is to order them. (Fells like it's a sorting algorithm ? wait for the rest)
<br>
Here is the funny part : you are restricted to a limited set of operations :
- sa (swap a)
- sb (swap b )
- ss (sa and sb)
- pa (push a)
- pb (push b)
- ra (rotate a)
- rb (rotate b)
- rr (ra and rb)
- rra (reverse rotate a)
- rrb (reverse rotate b)
- rrr (rra and rrb)

So it fells more like a game than a true sorting problem, but it is still interesting.
My approach was to imitate to closest I could with the operations a merge sort. By doing a fixed amount of pass, it filtered the numbers.
