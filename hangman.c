#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Word_with_hint {
    char word[100];
    char hints[3][500];
    char category[50];
} wordd;

void drawhangman(int tries);

int is_in_array(const char arr[], int size, char letter) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == letter) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("====================================================\n");
    printf("           WELCOME TO ARCADE HANGMAN!               \n");
    printf("====================================================\n");
    printf(" HOW TO PLAY:\n");
    printf("  * Guess the secret word one letter at a time.\n");
    printf("  * You have 6 lives per round before the drawing\n");
    printf("    is complete.\n");
    printf("  * Beat an 8-round session to conquer the game!\n\n");
    printf(" SCORING & COMBO STREAKS:\n");
    printf("  * Correct Letter : +100 pts x Active Streak\n");
    printf("  * Wrong Letter   : -1 Life & resets Streak to 0\n");
    printf("  * Win Bonus      : +20 pts for each life saved\n\n");
    printf(" SPECIAL POWER-UPS & GAMBLES:\n");
    printf("  * Type '$' : Buy Extra Hint (150 pts, then 250 pts)\n");
    printf("  * Type '?' : Buy a Letter (Costs 300 pts)\n");
    printf("  * Type '!' : All-In Word Guess (+500 Jackpot if\n");
    printf("               right, Instant Game Over if wrong!)\n");
    printf("====================================================\n\n");

    wordd arr[] = {
        // --- BOLLYWOOD (10 words) ---
        {"SHOLAY",     {"Classic 1975 blockbuster set in Ramgarh.", "Features iconic characters Jai, Veeru, and Thakur.", "Main villain is Gabbar Singh asking 'Kitne aadmi the?'"}, "Bollywood"},
        {"DANGAL",     {"Biographical sports drama based on real wrestlers.", "A father trains his two daughters in Haryana.", "Starring Aamir Khan as Mahavir Singh Phogat."}, "Bollywood"},
        {"LAGAAN",     {"Period drama set during British colonial rule.", "Villagers bet their annual tax on a single game.", "A high-stakes cricket match led by Bhuvan."}, "Bollywood"},
        {"BAAHUBALI",  {"Grand two-part Indian epic fantasy blockbuster.", "Set in the fictional kingdom of Mahishmati.", "Left India asking why Kattappa killed him."}, "Bollywood"},
        {"MUNNABHAI",  {"Comedy-drama about a kind-hearted Mumbai underworld don.", "He enrolls in a medical college to fulfill his father's dream.", "Uses 'Jadoo Ki Jhappi' alongside his sidekick Circuit."}, "Bollywood"},
        {"JAWAN",      {"High-octane vigilante action thriller.", "Features a dual father-son role.", "Starring Shah Rukh Khan and Nayanthara."}, "Bollywood"},
        {"ANDHADHUN",  {"Dark comedy thriller involving a series of murders.", "The protagonist plays the piano at a restaurant.", "He pretends to be visually impaired for his music."}, "Bollywood"},
        {"STREE",      {"Horror-comedy set in the small town of Chanderi.", "Men are mysteriously abducted during a four-day festival.", "People write 'O Stree Kal Aana' on their walls."}, "Bollywood"},
        {"DRISHYAM",   {"Suspense thriller centered around a middle-class family.", "The protagonist is a fourth-grade dropout cable operator.", "He uses movie plots to build an airtight alibi for October 2nd."}, "Bollywood"},
        {"DON",        {"Stylish action thriller about an underworld boss.", "A lookalike is planted by the police to infiltrate the gang.", "Catching him is impossible across eleven countries."}, "Bollywood"},

        // --- CRICKET (10 words) ---
        {"YORKER",     {"A lethal fast-bowling delivery.", "Pitches right inside the batter's crease.", "Aimed directly at the batter's toes or base of the stumps."}, "Cricket"},
        {"GOOGLY",     {"A deceptive spin-bowling variation.", "Bowled out of the back of the hand by a leg-spinner.", "Turns the exact opposite way the batter expects."}, "Cricket"},
        {"HELICOPTER", {"An unconventional, high-power batting shot.", "Developed to counter full-length yorkers in death overs.", "MS Dhoni's signature wristy whip over mid-wicket."}, "Cricket"},
        {"CENTURY",    {"A major personal batting milestone.", "Requires surviving at the crease for a long innings.", "Scored when a single batter reaches 100 runs."}, "Cricket"},
        {"DUCKWORTH",  {"A statistical system used in limited-overs cricket.", "Only comes into play when bad weather interrupts a match.", "Calculates revised target scores in rain-hit games."}, "Cricket"},
        {"POWERPLAY",  {"A special phase of fielding restrictions.", "Designed to encourage aggressive strokeplay.", "Only two fielders are allowed outside the 30-yard circle initially."}, "Cricket"},
        {"HATTRICK",   {"A rare and celebrated bowling achievement.", "Can even be split across two different overs.", "Dismissing three batters on three consecutive deliveries."}, "Cricket"},
        {"SUPEROVER",  {"An intense tie-breaking format.", "Each team nominates three batters and one bowler.", "A one-over eliminator played when a T20 match ends level."}, "Cricket"},
        {"SLOGSWEEP",  {"An aggressive cross-batted shot against spinners.", "The batter drops down onto one knee.", "Launched high over deep mid-wicket for a maximum."}, "Cricket"},
        {"DOOSRA",     {"A tricky variation bowled by an off-spinner.", "Released with a different wrist orientation.", "Spins away from a right-hander instead of turning in."}, "Cricket"},

        // --- STREET FOOD (10 words) ---
        {"GOLGAPPA",   {"India's undisputed king of street snacks.", "Known by different names like Puchka and Pani Puri.", "Crispy hollow puri filled with spicy tamarind water."}, "StreetFood"},
        {"VADAPAV",    {"An affordable, handheld everyday snack.", "Served inside a soft bun with dry garlic chutney.", "Mumbai's iconic spicy potato fritter burger."}, "StreetFood"},
        {"SAMOSA",     {"A crunchy, deep-fried savory snack.", "Best enjoyed hot with mint chutney and chai.", "Golden pastry triangle stuffed with spiced potatoes and peas."}, "StreetFood"},
        {"JALEBI",     {"A bright, festive Indian sweet.", "Made by piping fermented batter into hot oil.", "Crispy orange spirals soaked in warm saffron sugar syrup."}, "StreetFood"},
        {"CHHOLE",     {"A rich, tangy North Indian curry.", "Cooked with black tea bags for a dark color.", "Spicy chickpeas famously paired with fluffy fried Bhature."}, "StreetFood"},
        {"POHA",       {"A light, wholesome morning breakfast dish.", "Very popular across Madhya Pradesh and Maharashtra.", "Flattened rice tempered with turmeric, peanuts, sev, and lemon."}, "StreetFood"},
        {"KACHORI",    {"A round, crispy, deep-fried stuffed snack.", "Famous in Rajasthan, Uttar Pradesh, and central India.", "Flaky pastry filled with spiced lentils or onions."}, "StreetFood"},
        {"BIRYANI",    {"A royal, aromatic one-pot rice delicacy.", "Often served with cooling raita and salan.", "Layered basmati rice slow-cooked with saffron and spices."}, "StreetFood"},
        {"MASALADOSA", {"A classic South Indian breakfast favorite.", "Served alongside coconut chutney and hot sambar.", "Crispy fermented crepe stuffed with spiced potato filling."}, "StreetFood"},
        {"KULFI",      {"A traditional frozen Indian dessert.", "Often served on a wooden stick or in a matka.", "Dense, slow-simmered milk ice cream flavored with pistachio."}, "StreetFood"},

        // --- DESI NOSTALGIA & COLLEGE LIFE (10 words) ---
        {"GULLIDANDA", {"A traditional outdoor street sport.", "Requires zero expensive gear to play in a lane.", "Played using a wooden stick and a small tapered peg."}, "DesiNostalgia"},
        {"ANTAKSHARI", {"A classic group party and road-trip game.", "Tests your memory of Bollywood songs.", "You sing a song starting with the last letter of the previous one."}, "DesiNostalgia"},
        {"SHAKTIMAAN", {"A beloved 1990s Indian television superhero.", "His clumsy alter ego was a journalist named Gangadhar.", "Gained superpowers through meditation and spun to fly."}, "DesiNostalgia"},
        {"MALGUDI",    {"A nostalgic setting from classic Indian literature.", "Brought to life in an iconic Doordarshan TV series.", "Fictional South Indian town created by R.K. Narayan."}, "DesiNostalgia"},
        {"CANTEEN",    {"The liveliest hangout spot on every campus.", "More lectures are skipped here than anywhere else.", "College headquarters fueled by cutting chai and Maggi."}, "DesiNostalgia"},
        {"CHAI",       {"An everyday beverage across every Indian street.", "Often brewed with ginger, cardamom, and masala.", "Served in small cutting glasses at every nukkad."}, "DesiNostalgia"},
        {"LUDO",       {"A classic four-color tabletop board game.", "Safe zones are marked with stars on the board.", "The game that instantly turns best friends into rivals."}, "DesiNostalgia"},
        {"TUITION",    {"An after-school routine for millions of students.", "Usually happens in the evening at a teacher's house.", "Extra classes where half the time went into gossiping."}, "DesiNostalgia"},
        {"PROXY",      {"A classic college classroom maneuver.", "Requires imitating a friend's voice convincingly.", "Answering roll call attendance for an absent friend."}, "DesiNostalgia"},
        {"JUGAAD",     {"A uniquely Indian approach to problem-solving.", "Turns broken items into working solutions.", "The legendary art of clever, low-cost improvisation."}, "DesiNostalgia"}
    };

    int total_words = sizeof(arr) / sizeof(arr[0]);
    char play;
    srand(time(NULL));

    int used[50] = {0};
    int word_played = 0;
    int wins = 0, losses = 0, streak = 0, score = 0;

    do {
        int cat_choice;
        char selected_cat[50];
        wordd active_word;

        printf("\n=== ROUND %d OF 8 ===\n", word_played + 1);
        printf("CHOOSE YOUR CATEGORY:\n");
        printf("  1. Bollywood\n");
        printf("  2. Cricket\n");
        printf("  3. Street Food\n");
        printf("  4. Desi Nostalgia & College Life\n");
        printf("  5. ALL CATEGORIES (40-Word Mega Mix!)\n");
        printf("  6. CUSTOM WORD (2-Player Pass & Play)\n");

        while (1) {
            printf("Enter choice (1-6): ");
            if (scanf("%d", &cat_choice) == 1 && cat_choice >= 1 && cat_choice <= 6) {
                break;
            }
            printf("Invalid input! Please enter a number from 1 to 6.\n");
            while (getchar() != '\n');
        }

        if (cat_choice == 6) {
            strcpy(active_word.category, "Custom");
            printf("\n--- 2-PLAYER CUSTOM WORD SETUP ---\n");
            printf("Player 1, enter the secret word (letters only, no spaces): ");
            scanf("%99s", active_word.word);

            for (int k = 0; active_word.word[k] != '\0'; k++) {
                active_word.word[k] = toupper((unsigned char)active_word.word[k]);
            }

            while (getchar() != '\n');

            for (int h = 0; h < 3; h++) {
                printf("Enter Hint %d (or press Enter to skip): ", h + 1);
                fgets(active_word.hints[h], 500, stdin);
                active_word.hints[h][strcspn(active_word.hints[h], "\n")] = '\0';
                if (strlen(active_word.hints[h]) == 0) {
                    strcpy(active_word.hints[h], "No extra clue provided for this level!");
                }
            }

            for (int s = 0; s < 45; s++) {
                printf("\n");
            }
            printf("=== SCREEN CLEARED! PLAYER 2, YOUR TURN! ===\n");
        } else {
            if (cat_choice == 1)      strcpy(selected_cat, "Bollywood");
            else if (cat_choice == 2) strcpy(selected_cat, "Cricket");
            else if (cat_choice == 3) strcpy(selected_cat, "StreetFood");
            else if (cat_choice == 4) strcpy(selected_cat, "DesiNostalgia");
            else                      strcpy(selected_cat, "ALL");

            int n;
            do {
                n = rand() % total_words;
            } while (used[n] == 1 || (strcmp(selected_cat, "ALL") != 0 && strcmp(arr[n].category, selected_cat) != 0));

            used[n] = 1;
            active_word = arr[n];
        }

        word_played++;

        int i = 0;
        char guessed[50];
        char guess;
        int max_try = 6;
        int count = 0;
        int correct_letter = 0;

        int hints_unlocked = 1;
        int hint_cost = 150;

        int len = strlen(active_word.word);
        char display[100];
        for (int k = 0; k < len; k++) {
            display[k] = '_';
        }
        display[len] = '\0';

        printf("\nCategory: %s | Number of letters: %d\n", active_word.category, len);
        printf("Hint 1 (Free): %s\n", active_word.hints[0]);
        printf("\n-----START GUESSING WORD-----\n");

        do {
            printf("\nWord: ");
            for (int k = 0; k < len; k++) printf("%c ", display[k]);
            printf("\n[Score: %d | Lives: %d | Next Hint ($): %s]\n",
                   score, max_try - count,
                   (hints_unlocked < 3) ? (hint_cost == 150 ? "150 pts" : "250 pts") : "MAXED");

            printf("Enter letter (or '$' Hint, '?' Letter, '!' Gamble): ");
            scanf(" %c", &guess);
            guess = toupper((unsigned char)guess);

            if (!isalpha((unsigned char)guess) && guess != '!' && guess != '?' && guess != '$') {
                printf("Letters or special commands ('$', '?', '!') only!\n");
                continue;
            }

            if (guess == '$') {
                if (hints_unlocked >= 3) {
                    printf("All 3 hints are already unlocked for this word!\n");
                    continue;
                }
                if (score < hint_cost) {
                    printf("You need %d more points to unlock Hint %d!\n", hint_cost - score, hints_unlocked + 1);
                    continue;
                }
                score -= hint_cost;
                printf("\n>>> HINT %d UNLOCKED (-%d pts): %s <<<\n",
                       hints_unlocked + 1, hint_cost, active_word.hints[hints_unlocked]);
                hints_unlocked++;
                hint_cost += 100;
                continue;
            }

            if (guess == '!') {
                printf("\nALL-IN GAMBLE! Enter the full word: ");
                char full_guess[150];
                scanf("%149s", full_guess);
                for (int k = 0; k < strlen(full_guess); k++) {
                    full_guess[k] = toupper((unsigned char)full_guess[k]);
                }
                if (strcmp(full_guess, active_word.word) == 0) {
                    printf("\nYOU DID IT!! THE WORD WAS CORRECT!\n");
                    correct_letter = len;
                    score += 500;
                    continue;
                } else {
                    printf("\nOh, YOU GOT IT ALL WRONG — K.O.!\n");
                    count = max_try;
                    drawhangman(count);
                    continue;
                }
            }

            if (guess == '?') {
                if (score < 300) {
                    printf("You still need %d points to buy a LETTER!!\n", 300 - score);
                    continue;
                } else {
                    score -= 300;
                    for (int k = 0; k < len; k++) {
                        if (display[k] == '_') {
                            char got = active_word.word[k];
                            for (int j = 0; j < len; j++) {
                                if (active_word.word[j] == got) {
                                    display[j] = got;
                                    correct_letter++;
                                }
                            }
                            guessed[i++] = got;
                            break;
                        }
                    }
                    printf("Letter revealed! Word so far: %s\n", display);
                    continue;
                }
            }

            int check = is_in_array(guessed, i, guess);
            if (check == 1) {
                printf("ALREADY GUESSED!! TRY A DIFFERENT LETTER\n");
                continue;
            } else {
                guessed[i] = guess;
            }

            int found = 0;
            for (int k = 0; k < len; k++) {
                if (active_word.word[k] == guess) {
                    found = 1;
                    if (display[k] == '_') {
                        display[k] = guess;
                        correct_letter++;
                    }
                }
            }

            if (found) {
                streak += 1;
                score += streak * 100;
                printf("Correct! (+%d pts | %dx Streak)\n", streak * 100, streak);
            } else {
                streak = 0;
                count++;
                printf("WRONG LETTER CHOSEN!! TRIES LEFT: %d\n", max_try - count);
                drawhangman(count);
            }
            i++;

        } while (count < max_try && correct_letter < len);

        if (correct_letter == len) {
            printf("\nYou win!! Good Game! The word was %s\n", active_word.word);
            wins += 1;
            score += (max_try - count) * 20;
        } else {
            printf("\nGame Over! Try Again.\n");
            losses += 1;
            printf("The word was %s\n", active_word.word);
        }

        printf("\n+-----------------------------------+\n");
        printf("|          ROUND SUMMARY            |\n");
        printf("+-----------------------------------+\n");
        printf("|  Total Score   : %-16d |\n", score);
        printf("|  Active Streak : %dx               |\n", streak);
        printf("|  Wins / Losses : %d W - %d L        |\n", wins, losses);
        printf("+-----------------------------------+\n");

        if (word_played == 8) {
            printf("\nCONGRATULATIONS!! YOU COMPLETED ALL 8 ROUNDS!\n");
            break;
        }

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &play);

    } while (toupper((unsigned char)play) == 'Y');

    printf("\n=====================================\n");
    printf("         FINAL GAME STATS            \n");
    printf("=====================================\n");
    printf("  Rounds Played : %d / 8\n", word_played);
    printf("  Final Score   : %d\n", score);
    printf("  Record        : %d Wins | %d Losses\n", wins, losses);
    printf("=====================================\n");
    printf("   Thanks for playing Arcade Hangman!\n");

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
