#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// The "box" containing the artist information
struct Artist {
    string name;
    string hometown;
};

// The "box" containing the song information with the artist info nested inside to keep it all together
struct Song {
    string title;
    Artist artist;
    string genre;
    int durationSeconds;
};

// Functions prototypes before main
string formatDuration(int);
void displayPlaylist(const Song &s);
void totalRuntime(const Song songDuration[], int size);
int longestSong(const Song s[], int size, int &index);
void searchByArtist(const Song list[], int size);
void searchByGenre(const Song list[], int size);
string toLower(string s);

/*  Main uses a for loop to populate the list array
    Each iteration writes one index up to 4 when it stops 
    Uses a for loop to extract the informstion from the array, calls the function displayPlaylist that has the logic to display in the correct form
    The playlist stats uses the function totalRuntime to sum all the seconds and convert to M:SS
    Longest song keeps track of the index where the song with most seconds was found to then display the name of the song and the duration in M:SS
    Call the functions searchByArtist and searchByGenre in the main function 
*/
int main() {
    Song list[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter information for Song " << i + 1 << ": " << endl;
        cout << "Title: ";
        getline(cin, list[i].title);
        cout << "Artist name: ";
        getline(cin, list[i].artist.name);
        cout << "Artist hometown: ";
        getline(cin, list[i].artist.hometown);
        cout << "Genre: ";
        getline(cin, list[i].genre);
        cout << "Duration (seconds): ";
        cin >> list[i].durationSeconds;
        cin.ignore();
    }

    cout << "\nYOUR PLAYLIST:" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". ";
        displayPlaylist(list[i]);
    }

    int idx;
    int maxDuration = longestSong(list, 5, idx);

    cout << "Playlist Stats: " << endl;
    totalRuntime(list, 5);
    cout << "  Longest song: " << list[idx].title << " (" << formatDuration(maxDuration) << ")" << endl;

    searchByArtist(list, 5);
    searchByGenre(list, 5);

    return 0;
}

/*  I prefered to set up a function to display the playlist so main would look cleaner
    I used the & reference so it would optimize memory (it will use the original instead of making a copy of it)
    Allied with the const makes it both efficient and safe (I am not changing the data, only displaying it)
*/
void displayPlaylist(const Song &s) {
        cout << s.title << endl;
        cout << "Artist: " << s.artist.name << " (" << s.artist.hometown << ")" << endl;
        cout << "Genre: " << s.genre << endl;
        cout << "Duration: " << formatDuration(s.durationSeconds) << endl << endl;
}
/*  At first I was trying to use the replace method where it would replace the "." for a ":" but I ended up changing to pure math logic
    This format already gets the minutes and seconds separately using division and remainder and transforms it into a string 
    Adds a 0 in case it is a single digit (< 10) then returns a proper string with M:SS
*/
string formatDuration(int inSeconds) {
    int m = inSeconds / 60;
    int s = inSeconds % 60;
    string secondStr = "";

    if (s < 10) {
        secondStr = "0" + to_string(s);
    }
    else {
        secondStr = to_string(s);
    }

    return to_string(m) + ":" + secondStr;
}

// Uses a for loop to sum up all the song's durations then transforms it into M:SS with the proper function
void totalRuntime(const Song songDuration[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += songDuration[i].durationSeconds;
    }

    cout << "  Total runtime: " << formatDuration(sum) << endl;

}

/*  Starts with the first song being the longest and then compares to all the other using the for loop 
    Keeps track of the index to then display the song's name on main 
*/
int longestSong(const Song s[], int size, int &index) {
    int longSong = s[0].durationSeconds;
    index = 0;

    for (int i = 1; i < size; i++) {
        if (s[i].durationSeconds > longSong) {
            longSong = s[i].durationSeconds;
            index = i;
        }
    }

    return longSong;
}

// Function to transform the string all in lower to make the search more accurate
string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

/*  Asks the user to type an artist they would like to search for then put it in the target variable 
    Starts with a boolean stating false (not found)
    Goes through the for loop seaching each index and comparing to the target artist
    If it finds display the song but keep search up until you hit size (this allows for more thn one song to be found)
    In case nothing was found display the not found message
*/
void searchByArtist(const Song list[], int size) {
    string target;
    cout << "\nSearch by artist: ";
    getline(cin, target);
    bool found = false;
    cout << "Songs by " << target << ":" << endl;
    for (int i = 0; i < size; i++) {
        if (toLower(list[i].artist.name) == toLower(target)) {
            cout << "  - " << list[i].title << " (" << formatDuration(list[i].durationSeconds) << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "  No songs found by that artist." << endl;
}

/*  Uses the same logic as the searchByArtist but now takes the genre as the search subject
    Goes through the for loop seaching each index and comparing to the target genre
*/
void searchByGenre(const Song list[], int size) {
    string target;
    cout << "\nSearch by genre: ";
    getline(cin, target);
    bool found = false;
    cout << "Songs in genre \"" << target << "\":" << endl;
    for (int i = 0; i < size; i++) {
        if (toLower(list[i].genre) == toLower(target)) {
            cout << "  - " << list[i].title << " (" << formatDuration(list[i].durationSeconds) << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "  No songs found in that genre." << endl;
}