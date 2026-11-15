#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Word_with_hint{
    const char word[100];
    const char hint[500];
    const char category[50];
}wordd;
void drawhangman(int try);
int is_in_array(const char arr[], int size, char letter) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == letter) {
            return 1; 
        }
    }
    return 0; 
}



int main(){
    printf("====================================================\n");
printf("           WELCOME TO ARCADE HANGMAN!               \n");
printf("====================================================\n");
printf(" HOW TO PLAY:\n");
printf("  * Guess the secret word one letter at a time.\n");
printf("  * You have 6 lives per round before the drawing\n");
printf("    is complete.\n");
printf("  * Beat all 8 unique words to conquer the game!\n\n");
printf(" SCORING & COMBO STREAKS:\n");
printf("  * Correct Letter : +100 pts x Active Streak\n");
printf("  * Wrong Letter   : -1 Life & resets Streak to 0\n");
printf("  * Win Bonus      : +20 pts for each life saved\n\n");
printf(" SPECIAL POWER-UPS & GAMBLES:\n");
printf("  * Type '?' : Buy a Letter (Costs 300 pts)\n");
printf("  * Type '!' : All-In Word Guess (+500 Jackpot if\n");
printf("               right, Instant Game Over if wrong!)\n");
printf("====================================================\n\n");
int cat_choice;
char selected_cat[50];


    char play;
    srand(time(NULL));
    int used[50]={0};
    int word_played=0;
    int wins = 0, losses = 0, streak = 0, score = 0;
    do{
        printf("CHOOSE YOUR CATEGORY:\n");
        printf("  1. Bollywood\n");
        printf("  2. Cricket\n");
        printf("  3. Street Food\n");
        printf("  4. Desi Nostalgia & College Life\n");
        printf("  5. ALL CATEGORIES (40-Word Mega Mix!)\n");
        while (1) {
    printf("Enter choice (1-5): ");
    if (scanf("%d", &cat_choice) == 1 && cat_choice >= 1 && cat_choice <= 5) {
        break; 
    }
    printf("Invalid input! Please enter a number from 1 to 5.\n");
    while (getchar() != '\n'); 
}

        if (cat_choice == 1)      strcpy(selected_cat, "Bollywood");
        else if (cat_choice == 2) strcpy(selected_cat, "Cricket");
        else if (cat_choice == 3) strcpy(selected_cat, "StreetFood");
        else if (cat_choice == 4) strcpy(selected_cat, "DesiNostalgia");
        else                      strcpy(selected_cat, "ALL");

    int i=0; 
    char guessed[50];
    char guess;
    int max_try=6;
    int count=0;
    int correct_letter=0;
   wordd arr[] = {
    // --- BOLLYWOOD (10 words) ---
    {"SHOLAY",     "Classic 1975 blockbuster featuring Jai, Veeru, and Gabbar Singh.", "Bollywood"},
    {"DANGAL",     "Record-breaking wrestling drama starring Aamir Khan as Mahavir Phogat.", "Bollywood"},
    {"LAGAAN",     "Villagers challenge British officers to a high-stakes cricket match.", "Bollywood"},
    {"BAAHUBALI",  "Epic fantasy blockbuster that left India asking why Kattappa killed him.", "Bollywood"},
    {"MUNNABHAI",  "A lovable Mumbai goon who goes to medical college with his sidekick Circuit.", "Bollywood"},
    {"JAWAN", "Shah Rukh Khan plays a dual father-son role in this high-octane vigilante action thriller.", "Bollywood"},
    {"ANDHADHUN",  "A dark thriller about a supposedly blind pianist who witnesses a murder.", "Bollywood"},
    {"STREE",      "A horror-comedy about a ghost who knocks on doors during a festival.", "Bollywood"},
    {"DRISHYAM",   "A clever cable operator uses movie plots to protect his family from the police.", "Bollywood"},
    {"DON",        "Catching him is not just difficult, it is impossible across eleven countries.", "Bollywood"},

    // --- CRICKET (10 words) ---
    {"YORKER",     "A deadly delivery aimed right at the batter's toes.", "Cricket"},
    {"GOOGLY",     "A deceptive wrist-spin delivery that turns the opposite way you expect.", "Cricket"},
    {"HELICOPTER", "MS Dhoni's signature wristy whip shot over mid-wicket.", "Cricket"},
    {"CENTURY",    "A milestone 100 runs scored by a single batter in one innings.", "Cricket"},
    {"DUCKWORTH",  "The mathematical formula used to recalculate targets in rain-hit matches.", "Cricket"},
    {"POWERPLAY",  "The fielding-restriction overs where batters swing hard for boundaries.", "Cricket"},
    {"HATTRICK",   "When a bowler dismisses three batters on three consecutive balls.", "Cricket"},
    {"SUPEROVER",  "A thrilling one-over tie-breaker used when a T20 match ends level.", "Cricket"},
    {"SLOGSWEEP",  "An aggressive kneeling shot launched high over deep mid-wicket.", "Cricket"},
    {"DOOSRA",     "An off-spinner's mystery ball that spins away instead of turning in.", "Cricket"},

    // --- STREET FOOD (10 words) ---
    {"GOLGAPPA",   "Crispy hollow puri filled with spicy tamarind water, also called Pani Puri.", "StreetFood"},
    {"VADAPAV",    "Mumbai's iconic spicy potato fritter burger served with green chutney.", "StreetFood"},
    {"SAMOSA",     "Crispy golden triangle stuffed with spiced potatoes and peas.", "StreetFood"},
    {"JALEBI",     "Deep-fried orange spirals soaked in warm saffron sugar syrup.", "StreetFood"},
    {"CHHOLE",     "Spicy chickpea curry famously paired with fluffy fried Bhature.", "StreetFood"},
    {"POHA",       "Light, flattened rice breakfast topped with sev, peanuts, and lemon.", "StreetFood"},
    {"KACHORI",    "Flaky, deep-fried stuffed pastry famous in Rajasthan and central India.", "StreetFood"},
    {"BIRYANI",    "Fragrant layered rice slow-cooked with spices, saffron, and herbs.", "StreetFood"},
    {"MASALADOSA", "Crispy South Indian fermented crepe stuffed with spiced potato filling.", "StreetFood"},
    {"KULFI",      "Dense, creamy traditional Indian ice cream often flavored with pistachio.", "StreetFood"},

        // --- DESI NOSTALGIA & COLLEGE LIFE (10 words) ---
    {"GULLIDANDA", "Classic street game played with a wooden stick and a small tapered peg.", "DesiNostalgia"},
    {"ANTAKSHARI", "Musical road-trip game where you sing a song starting with the last letter.", "DesiNostalgia"},
    {"SHAKTIMAAN", "India's iconic 90s spinning superhero whose alter ego was Gangadhar.", "DesiNostalgia"},
    {"MALGUDI",    "Fictional South Indian town created by RK Narayan that defined 90s TV.", "DesiNostalgia"},
    {"CANTEEN",    "The real headquarters of every college campus, fueled by chai and Maggi.", "DesiNostalgia"},
    {"CHAI",       "The ultimate Indian fuel served in cutting glasses at every nukkad.", "DesiNostalgia"},
    {"LUDO",       "The classic four-player board game that turns best friends into rivals.", "DesiNostalgia"},
    {"TUITION",     "Evening extra classes where half the time went into gossiping with friends.", "DesiNostalgia"},
    {"PROXY",      "The risky art of answering roll call for an absent friend in lecture.", "DesiNostalgia"},
    {"JUGAAD",     "The legendary Indian superpower of fixing anything with clever improvisation.", "DesiNostalgia"}
   };


int total_words = sizeof(arr) / sizeof(arr[0]);

    int n;
    do{
        n=rand()%total_words;
    }while(used[n] == 1 || (strcmp(selected_cat, "ALL") != 0 && strcmp(arr[n].category, selected_cat) != 0));
    used[n]=1;
    word_played++;
    int len=strlen(arr[n].word);
    char display[100];
    for (int i = 0; i < len; i++) {
        display[i] = '_';
    }
    display[len] = '\0';
    printf("Number of letters: %d\n",len);
    printf("Hint: %s\n",arr[n].hint);
    printf("\n\n-----START GUESSING WORD-----\n\n");
    do{
        printf("\nWord: ");
for (int k = 0; k < len; k++) printf("%c ", display[k]);
printf("\n");
        printf("Enter letter:");
        scanf(" %c",&guess);
        guess=toupper(guess);
        if (!isalpha((unsigned char)guess) && guess != '!' && guess != '?') {
            printf("Letters only!\n");
            continue;
        }
        if (guess=='!'){
            printf("\n\nALL-IN GAMBLE! Enter the full word: \n");
            char full_guess[150];
            scanf("%s",full_guess);
            for(int i=0;i<strlen(full_guess);i++){
                full_guess[i]=toupper(full_guess[i]);
            }
            if(strcmp(full_guess,arr[n].word)==0){
                printf("\nYOU DID IT!! THE WORD WAS CORRECT\n");
                correct_letter=len;
                score+=500;
                continue;
            }
            else {
                printf("\nOh YOU GOT IT ALL WRONG K.o.\n");
                count=max_try;
                continue;
            }
        }
        if (guess=='?'){
            if (score<300) {
                printf("You still need %d points to buy a LETTER!!",300-score);
                continue;
            }
            else {
                score -= 300;
                for (int k = 0; k < len; k++) {
                    if (display[k] == '_') {
                        char got = arr[n].word[k];
                        for (int j = 0; j < len; j++) {
                            if (arr[n].word[j] == got) {
                                display[j] = got;
                                correct_letter++;
                            }
                        }
                        guessed[i++] = got;
                        break;
                    }
                }
                printf("%s\n", display);
                continue;
            }
        }
        int check=is_in_array(guessed,i,guess);
        if (check==1){
             printf("ALREADY GUESSED!! TRY A DIFFERENT LETTER\n\n");
             continue;
        }
        else{guessed[i]=guess;}
        int found=0;
        for(int i=0;i<len;i++){
            if (arr[n].word[i]==guess) {
                found=1;
            if(display[i]=='_'){
                display[i]=guess;
                correct_letter++;
            }
        }
        }
        if (found) {
            printf("Correct Word so far Go ahead Complete it %s\n",display);
            streak+=1;
            score+=streak*100;
        }
        else{
            streak=0;
            count++;
            printf("WRONG LETTER CHOSEN!! TRIES LEFT: %d\n",max_try-count);
            drawhangman(count);
        }
        i++;
    }while(count<max_try && correct_letter<len);
    if (correct_letter==len){
        printf("\nYou win!! Good Game\n");
        wins+=1;
        score+=(max_try-count)*20;
    }
    else{
         printf("\nGame Over Try Again\n");
         losses+=1;
         printf("The word was %s",arr[n].word);
    }
    
    printf("\n+-----------------------------------+\n");
    printf("|          ROUND SUMMARY            |\n");
    printf("+-----------------------------------+\n");
    printf("|  Total Score   : %-16d |\n", score);
    printf("|  Active Streak : %dx               |\n", streak);
    printf("|  Wins / Losses : %d W - %d L        |\n", wins, losses);
    printf("+-----------------------------------+\n");
    if (word_played==8){
        printf("CONGRATULATIONS!! YOU COMPLETED ALL THE ROUNDS\n");
        break;
    }

    printf("\n\nDo you want to play again?(Y/N) ");
    scanf(" %c",&play);
}while(toupper(play)=='Y');
    return 0;

}
void drawhangman(int tries) {
    printf("\n  +---+\n");
    printf("  |   |\n");
    printf("  %c   |\n", (tries >= 1) ? 'O' : ' ');
    printf(" %c%c%c  |\n", (tries >= 3) ? '/' : ' ', (tries >= 2) ? '|' : ' ', (tries >= 4) ? '\\' : ' ');
    printf(" %c %c  |\n", (tries >= 5) ? '/' : ' ', (tries >= 6) ? '\\' : ' ');
    printf("      |\n=========\n");
}
