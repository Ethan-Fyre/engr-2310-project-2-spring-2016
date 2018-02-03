/*pirate_speak.cpp
   Ethan Sayles
   Apr 4, 2016
   Purpose:Translate a user-entered phrase into pirate-speak.
 */

//CHANGED FRIEND TO "BUCKO" SO THAT "MY FRIEND" BECOMES "ME BUCKO" RATHER THEN "ME ME BUCKO"

#include <iostream>
#include <assert.h>

using namespace std;

//function prototypes
void user_word(string prompt);
string translate(string phrase);
bool translate_test();

int main() {
    cout << "This be th' shiver me timbers pirate translator." << endl;

    //prompt the user to enter a phrase and convert said phrase to pirate speak
    user_word("Enter a phrase, matey!");

    return 0;
}

/** Turns an english word into a pirate word if it is a specific word, otherwise leaves it English
 * @param phrase the string to be converted
 * @return pirate_word the converted word
 */
string translate(string phrase){
    const int SIZE = 44;               //size of the pirate words array and the english words array
    string pirate_word = "";          //The pirate version of phrase to be returned
    string pirate_words[SIZE] = {"ahoy","yo-ho-ho","broadside","th'","barnacle-covered","me","bucko","matey","ye","thar",
                                 "scurvy dog","be","whar","be tellin'","buried treasure","aye aye","afeard","belay","blaggard",
                                 "booty","bounty","grub","cap'n","cot","cutlass","fore","hornswaggler","lass","lad","hearties",
                                 "pillage","plunder","pox","shanty","shipshape","smartly","spyglass","swab","yer","be","be","goin",
                                 "t'","doin'"};   //List of pirate words
    string english_words[SIZE] = {"hello", "hi","nearby","the","old","my","friend","sir","you","there","stranger","is","where",
                                  "tell","bank","alright","afraid","stop","liar","money","reward","food","captain","bed","sword",
                                  "forward","cheater","girl","boy","friends","rob","steal","disease","song","neat","quickly",
                                  "telescope","clean","your","am","are","going","to","doing"};  //List of english words
    //check if the phrase matches an english word, and if so make pirate_word be the equivalent pirate word, otherwise leave it how it is
    for (int i = 0; i < SIZE; i++){
        if (phrase == english_words[i]){
            pirate_word = pirate_words[i];
            break;
        }//end if
        else{
            pirate_word = phrase;
        }// end else
    }//end for
    return pirate_word;
}//end translate

/** Turns an english phrase into a pirate phrase
 * @param prompt the message to prompt the user_phrase
 * @return nothing
 */
void user_word(string prompt){
    string user_phrase = "";          //User-entered English phrase
    string word = "";                 //Variable to store individual words to change
    string pirate_phrase = "";        //Computer-returned pirate translation of user_phrase

//cycle multiple times until the user quits, reprompting each time
    while (true){
        cout << prompt << endl;
        getline(cin,user_phrase);
        //how to exit the loop
        if (user_phrase == "arr"){
            break;
        }//end "arr" if
        //test if all the english words properly convert
        else if (user_phrase == "unit-test"){
            translate_test();
            break;
        }//end "unit-test" if
        //cycle through letter by letter, and if you hit a space, ,,or ., then translate the word, add it too the output
        //phrase and add the corresponding symbol
        for (int i = 0; i < user_phrase.length();i++){
            if (user_phrase[i] != ','){
                if (user_phrase[i] != '.'){
                    if (user_phrase[i] != char(32)){
                            word += user_phrase[i];

                    }//end " " if statement
                    else{
                        pirate_phrase += translate(word);
                        pirate_phrase += user_phrase[i];
                        word.clear();
                    }//end " " else statement
                }//end "." if statement
                else {
                    pirate_phrase += translate(word);
                    pirate_phrase += user_phrase[i];
                    word.clear();
                }//end "." else statement
            }//end "," if statement
            else{
                pirate_phrase += translate(word);
                pirate_phrase += user_phrase[i];
                word.clear();
            }//end "," else statement
        }//end for loop
        pirate_phrase += translate(word);
        cout << pirate_phrase << endl;
        pirate_phrase = "";
        word.clear();
    }//end while loop
    return;
}//end user_word

/** tests if the phrases get correctly translated
 * @param nothing
 * @return bool if all are true
 */
bool translate_test(){
    assert(translate("hello") == "ahoy");
    assert(translate("hi") == "yo-ho-ho");
    assert(translate("nearby") == "broadside");
    assert(translate("the") == "th'");
    assert(translate("old") == "barnacle-covered");
    assert(translate("my") == "me");
    assert(translate("friend") == "bucko");
    assert(translate("sir") == "matey");
    assert(translate("you") == "ye");
    assert(translate("there") == "thar");
    assert(translate("stranger") == "scurvy dog");
    assert(translate("is") == "be");
    assert(translate("where") == "whar");
    assert(translate("tell") == "be tellin'");
    assert(translate("bank") == "buried treasure");
    assert(translate("alright") == "aye aye");
    assert(translate("afraid") == "afeard");
    assert(translate("stop") == "belay");
    assert(translate("liar") == "blaggard");
    assert(translate("money") == "booty");
    assert(translate("reward") == "bounty");
    assert(translate("food") == "grub");
    assert(translate("captain") == "cap'n");
    assert(translate("bed") == "cot");
    assert(translate("sword") == "cutlass");
    assert(translate("forward") == "fore");
    assert(translate("cheater") == "hornswaggler");
    assert(translate("girl") == "lass");
    assert(translate("boy") == "lad");
    assert(translate("friends") == "hearties");
    assert(translate("rob") == "pillage");
    assert(translate("steal") == "plunder");
    assert(translate("disease") == "pox");
    assert(translate("song") == "shanty");
    assert(translate("neat") == "shipshape");
    assert(translate("quickly") == "smartly");
    assert(translate("telescope") == "spyglass");
    assert(translate("clean") == "swab");
    assert(translate("your") == "yer");
    assert(translate("am") == "be");
    assert(translate("are") == "be");
    assert(translate("going") == "goin");
    assert(translate("to") == "t'");
    assert(translate("doing") == "doin'");
}