/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include "main.h"


int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize)
{
    int res = 0;
    int q_size;
    char temp[10] = {0};
    char *str;
    
    GQueue *q = g_queue_new();
    GHashTable *visited = g_hash_table_new(g_str_hash, g_str_equal);
    GHashTable *word_list = g_hash_table_new(g_str_hash, g_str_equal);
    
    for(int i = 0; i < wordListSize; i++)
        g_hash_table_insert(word_list, wordList[i], wordList[i]);
    
    g_hash_table_add(visited, beginWord);
    g_queue_push_tail(q, beginWord);
    
    while(!g_queue_is_empty(q)) {
        q_size = g_queue_get_length(q);
        for(int j = 0; j < q_size; j++) {
            str = g_queue_pop_head(q);
            if(strcmp(str, endWord) == 0) {
                return res+1;
            }
            for(int i = 0; i < strlen(str); i++) {
                strcpy(temp, str);
                for(char a = 'a'; a <= 'z'; a++) {
                    temp[i] = a;
                    if((g_hash_table_contains(word_list, temp) &&
                        !g_hash_table_contains(visited, temp))) {
                        g_queue_push_tail(q, g_hash_table_lookup(word_list, temp));
                        g_hash_table_add(visited, g_hash_table_lookup(word_list, temp));
                    }
                }
            }
        }
        res++;
    }
    return 0;
}
void word_ladder()
{
    char *beginWord = "a";
    char *endWord = "c";
    int wordListSize = 3;
    char temp[][100] = {"a","b","c"};
    char **wordList = calloc(1, sizeof(wordList) * wordListSize);
    for(int i = 0; i < wordListSize; i++) {
        wordList[i] = calloc(1, sizeof(wordList[i]) * 5);
        strcpy(wordList[i], temp[i]);
    }
    int res = ladderLength(beginWord, endWord, wordList, wordListSize);
    printf("Ladder Length : %d\n", res);

}

