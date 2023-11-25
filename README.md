# invokerProblem

This is the setup and implementation to a programming challenge. 
I was wondering what the full combination of keystrokes to cast all of his spells would be. Rather than simply going to the wiki page and pulling up his combos: https://static.wikia.nocookie.net/dota2_gamepedia/images/2/23/Invoke_list.png/revision/latest?cb=20161223024611, I figured it'd be more fun to write an algorithm to do it for me.


Here is the setup:
1. There exists in the game Dota 2 a character named Invoker.
2. Invoker is unique in that the spells he casts must be created using a combination of three orbs: Quas, Wex and Exhort
3. Therefore, three quas orbs will create the spell Cold Snap, two Wex orbs and one Exhort orb will create the spell Alacrity, and so on.
4. The order the orbs are pressed do not matter, just the number of each orb when Invoker uses Invoke to create a new spell.
5. Therefore, Quas Quas Exhort is exactly the same as Exhort Quas Quas.
6. There exist exactly 10 unique permutations.

Here is the problem:
1. Write an algorithm to prove the number of unique permutations for Invoker's spells
2. Output to the console each unique permutation, or state, of Invoker's orbs when he invokes a new spell
3. Once all unique permutations have been printed, print the key presses for each of the spells (q, w, e), as well as the key for invoke (r) and the key to cast the spell (e).
4. The length of the 'full combo' should be (3 + 2) * 10.

The implementation:
1. Create an enum OrbType. The enum will store the number of each orb (quas, wex, exhort).
2. Create a vector to hold Invoker's orbs called currentPermutation.
3. Create another vector to hold snapshots of each state called permutations. We'll keep all non-unique permutations in here.
4. Create a third vector called uniquePermutations. Later, we'll iterate through the permutations and keep only ones with unique numbers of each orb.
5. Create a recursive function generateOrbPermutations(permutations, currentPermutation, orbsLeft). orbsLeft is an int that ensures the base case of the function begins at 3.
  a. Use an if statement to check if we've used all the orbs and return if true
  b. use a 3-count for loop to push the current value of i into the currentPermutation vector, then call the function again, but with orbsLeft - 1
  c. after the recursive function call, pop the last value of currentPermutation
6. Create a bool function to compare the BoolType vectors in uniquePermutations against those in permutations using a nested for loop. If the same number of quas, wex and exhort are NOT found in an iteration, push the iteration into the uniquePermutation vector.
7. Initialize an empty string called combo
8. Iterate over each orb in each object in uniquePermutation and output to the console the name of the orb, and add q, w, or e to the combo string based on the same
9. Add 'rd' to the combo string after each object is parsed
10. Finally, output the full combo string: qqqrdqqwrdqqerdqwqrdqwwrdqwerdqeqrdqewrdqeerdwqqrdwqwrdwqerdwwqrdwwwrdwwerdweqrdwewrdweerdeqqrdeqwrdeqerdewqrdewwrdewerdeeqrdeewrdeeerd

The last step to this would be to find the OPTIMAL key presses, as Invoker's spells are determined by orb count, not key press. Thus: q q q r w r would cast both cold snap and ice path, using six key presses instead of 8.
