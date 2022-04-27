# push_swap

## Info
![image](https://user-images.githubusercontent.com/94758944/165584190-b54da7bc-9b8f-4a1f-846c-d12693701b6c.png)

## How to use
- make
- make bonus

## Mandatory part
ARG=\`ruby -e "puts (0..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG
- The “push_swap” program
> vizualisator https://github.com/o-reo/push_swap_visualizer.git
> - random list of 100: **650 - 680** steps
> - random list of 500: **4800 - 4900** steps 

## Bonus part
- The “checker” program

##Command
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time. 
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.
