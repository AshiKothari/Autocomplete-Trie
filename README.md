# Autocomplete-Trie
 A simple idea that recommends to auto-complete the query based on the strings stored in the Trie. It is assumed trie stores past searches by the users.
 Given a query prefix, we search for all words having this query.
 <br>
## Improvements
The number of matches might just be too large if the strings stored are large. So we have to be selective while displaying them. We can restrict ourselves to display only the relevant results. We can consider the past search history and show only the most searched matching strings as relevant results.
Store another value for the each node where isleaf=True which contains the number of hits for that query search. For example if “ashi” is searched 8 times, then we store this 8 at the last node for “ashi”. Now when we want to show the recommendations, we display the top k matches with the highest hits
 
