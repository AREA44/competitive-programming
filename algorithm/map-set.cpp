#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;

set<int> si;
map<string, int> msi;

int main() {
    printf("Map:\n");
    /*  suppose we enter these 7 name-score pairs below */
    msi["john"] = 78;   si.insert(78);
    msi["billy"] = 69;  si.insert(69);
    msi["andy"] = 80;   si.insert(80);
    msi["steven"] = 77; si.insert(77);
    msi["felix"] = 82;  si.insert(82);
    msi["grace"] = 75;  si.insert(75);
    msi["martin"] = 81; si.insert(81);
    /*  then the internal content of msi MAY be something like this:
        re-read balanced BST concept if you do not understand this diagram
        the keys are names (string)!
                            (grace,75)
                    (billy,69)      (martin,81)
            (andy,80)   (felix,82) (john,78)  (steven,77)
        iterating through the content of msi will give a sorted output
        based on keys (names)*/
    for (map<string, int>::iterator it = msi.begin(); it != msi.end(); it++)
        printf("%s %d\n", ((string)it->first).c_str(), it->second);
    printf("\n");
    /* map can also be used like this */
    printf("steven's score is %d, grace's score is %d\n",msi["steven"], msi["grace"]);
    printf("\n");
    /*  interesting usage of lower_bound and upper_bound
        display data between ["f".."m") ('felix' is included, martin' is excluded) */
    for (map<string, int>::iterator it = msi.lower_bound("f"); it != msi.upper_bound("m"); it++)
        printf("%s %d\n", ((string)it->first).c_str(), it->second);
    printf("\n");

    printf("Set:\n");
    /*  the internal content of si MAY be something like this
        the keys are values (integers)!
                       (78)
                (75)            (81)
           (69)    (77)     (80)    (82)    */
    printf("%d\n", *si.find(77));
    /*  returns [69, 75] (these two are before 77 in the inorder traversal of this BST) */
    for (set<int>::iterator it = si.begin(); it != si.lower_bound(77); it++)
        printf("%d ", *it);
    printf("\n");
    /*  returns [77, 78, 80, 81, 82] (these five are equal or after 77 in the inorder traversal of this BST*/
    for (set<int>::iterator it = si.lower_bound(77); it != si.end(); it++)
        printf("%d ", *it);
    printf("\n");
    if (si.find(79) == si.end())
        printf("79 not found\n");
    return 0;
}
