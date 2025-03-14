bool vote(int voter, int rank, string name)

for one to win the, one most hold a majority of the votes,  if we have 10 voters, one of the candidates must hold a majority of those votes so 6. 6/10 will be declared winner. 

However, if there is no candidate that holds a majority of votes, we do a process called runoff. This process takes the candidate with the lowest number of votes and elements the voters first choice, we then take their second choice as a vote and give it to the corrisponding candidate, and if there is yet to be a winner we continue this process until there is a winning candidate. 

But if a voters second choice is a candidate that has already been eliminated, we then go to their third choice and take that candidate instead. 

when representing a candidates we would like to represent their name, their number of votes, and a boolean to know if they've beem eliminated or not

this is how we'll keep track of who wins, but how do we keep track of the voters (who their preferences are)?

to do that we're going to represest preferences using the 2d array preferences. 




vote. 
- Look for a candidate called *name*
- If candidate found, update preferences so that they are 
  the voter's rank prference, and *return true*
- If no candidate found, don't update any preferences and 
  *return false*

  so how this kinda works is we have candidates with corrisponding indexs  

  Alice[0]
  Bob[1]
  Charlie[2]

so if i voter 0 had voted for Alice, Charlie, then Bob the 2d preference array would then have index 0 at [0][0] indicating Alice is their first vote, Bob[1] at [0][1]
indicating Bob is their second vote, Charlie[2] at [0][2]
indicating Charlie is their third vote. 

thats just voter 0, but there can be as many as 0...100 voters and 0...9, the same rules follow even as the data grows. 

so the preference array would now look like

[
voter 1: [0, 2, 1]
voter 2: [1, 0, 2]
voter 3: [1, 2, 0]
]

Alice has 1 Vote
Bob has 2 Votes, thats the end no more need to be done, Bob holds the majority 2/3 
