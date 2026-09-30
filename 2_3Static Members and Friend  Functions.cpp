1 # include < iostream >
2 # include < string >
3 using namespace std ;
4
5 class StaticExample {
6 private :
7 static int count ;
8 int id ;
9
10 public :
11 StaticExample () {
12 count ++;
13 id = count ;
14 }
15
16 static void showCount () {
17 cout << " Total objects created : " << count << endl ;
18 }
19
20 void display () const {
21 cout << " Object ID: " << id << endl ;
22 }
23 };
24
25 int StaticExample :: count = 0;
26
27 class ClassA ;
28 class ClassB ;
29
30 class ClassA {
31 private :
32 int valueA ;
33 public :
34 ClassA (int v ) : valueA ( v ) {}
35 friend void compareValues ( ClassA &a , ClassB & b ) ;
36 };
37
38 class ClassB {
39 private :
40 int valueB ;
41 public :
42 ClassB (int v ) : valueB ( v ) {}
43 friend void compareValues ( ClassA &a , ClassB & b ) ;
44 };
45
46 void compareValues ( ClassA &a , ClassB & b ) {
47 cout << " Value in ClassA : " << a . valueA << endl ;
48 cout << " Value in ClassB : " << b . valueB << endl ;
49 if ( a . valueA > b . valueB )
50 cout << " ClassA value is greater " << endl ;
51 else if ( a . valueA < b . valueB )
52 cout << " ClassB value is greater " << endl ;
53 else
54 cout << " Both values are equal " << endl ;
55 }
56
57 class SecretData {
58 private :
59 string password ;
60 int secretNumber ;
61 public :
62 SecretData ( string p , int n ) : password ( p ) , secretNumber ( n ) {}
63 friend class FriendClassExample ;
64 };
65
66 class FriendClassExample {
67 public :
68 void displaySecret ( SecretData & s ) {
69 cout << " Password : " << s . password << endl ;
70 cout << " Secret Number : " << s . secretNumber << endl ;
71 }
72 };
73
74 int main () {
75 cout << "=== Static Members === " << endl ;
76 StaticExample s1 , s2 , s3 ;
77 StaticExample :: showCount () ;
78
79 cout << "\n=== Friend Function === " << endl ;
80 ClassA a (50) ;
81 ClassB b (30) ;
82 compareValues (a , b ) ;
83
84 cout << "\n=== Friend Class === " << endl ;
85 SecretData secret (" myPassword123 ", 999) ;
86 FriendClassExample friendObj ;
87 friendObj . displaySecret ( secret ) ;
88
89 return 0;
90 }
91
