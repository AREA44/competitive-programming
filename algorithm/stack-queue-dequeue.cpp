#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "queue"
#include "stack"
#include "deque"
using namespace std;

stack<char> Sc;
queue<char> Qc;
deque<char> Dc;

int main() {
    printf("Stack:\n");
    printf("Stack empty? %s\n", Sc.empty() ? "Yes" : "No");
    Sc.push('a');Sc.push('b');Sc.push('c'); // Content of Sc is currently like this: <->[c,b,a].
    printf("%c\n", Sc.top());   //Output is 'c'.
    Sc.pop();                   //Pop topmost
    printf("%c\n", Sc.top());   //Output 'b'
    printf("Stack empty? %s\n", Sc.empty() ? "Yes" : "No");
    printf("\n");

    printf("Queue\n");
    printf("Queue empty? %s\n", Qc.empty() ? "Yes" : "No");
    while (!Sc.empty()) {       //Stack Sc still has 2 more items
        Qc.push(Sc.top());      //Enqueue 'b', and then 'a'
        Sc.pop();
    }
    Qc.push('d');               //Add one more item. Content of Qc is currently like this: ->[d,a,b]->.
    printf("%c\n", Qc.front()); //Prints 'b'
    printf("%c\n", Qc.back());  //Prints 'd'
    while (!Qc.empty()) {       //Queue Qc still has 3 more items
        printf("%c\n", Qc.front()); //Take the front first
        Qc.pop();                   //Before popping (dequeue-ing) it
    }
    printf("\n");

    printf("Deque:\n");
    Dc.push_back('a'); Dc.push_back('b'); Dc.push_back('c'); //Content of Dc is currently like this: <->[a, b, c]<->.
    printf("%c - %c\n", Dc.front(), Dc.back()); //Prints 'a - c'
    Dc.push_front('d'); //Content of Dc is currently like this: <->[d, a, b, c]<->.
    printf("%c - %c\n", Dc.front(), Dc.back()); //Prints 'd - c'
    Dc.pop_back();  //Pop last item of deque
    printf("%c - %c\n", Dc.front(), Dc.back()); //Prints 'd - b'
    Dc.pop_front(); //Pop first item of deque
    printf("%c - %c\n", Dc.front(), Dc.back()); //Prints 'a - b'
    printf("\n");
    return 0;
}
