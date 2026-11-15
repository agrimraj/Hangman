# 🕹️ Arcade Hangman — Desi Edition

A retro arcade-style browser Hangman game packed with Indian pop-culture categories, streak multipliers, tactical power-ups, and custom synthesized desi sound effects and voice commentary.

---

## 🎮 How to Play

1. **Choose a Category:** Pick from four themed categories, jump into the 40-word **All categories** mega-mix, or set up a 2-player pass-and-play **Custom word**.
2. **Guess the Word:** Click the on-screen keys or use your physical keyboard (`A–Z`) to uncover the hidden letters before your **6 lives** run out.
3. **Clear the Cabinet:** Survive all **8 rounds** to earn a final arcade rank (`S`, `A`, `B`, `C`, or `D`) and share your scorecard.

---

## 📂 Categories Included

* **Bollywood:** Iconic blockbusters and thrillers (*Sholay*, *Dangal*, *Lagaan*, *Baahubali*, *Munnabhai*, *Jawan*, *Andhadhun*, *Stree*, *Drishyam*, *Don*).
* **Cricket:** Classic shots, deliveries, and match formats (*Yorker*, *Googly*, *Helicopter*, *Century*, *Duckworth*, *Powerplay*, *Hattrick*, *Superover*, *Slogsweep*, *Doosra*).
* **Street Food:** Beloved Indian snacks and delicacies (*Golgappa*, *Vadapav*, *Samosa*, *Jalebi*, *Chhole*, *Poha*, *Kachori*, *Biryani*, *Masaladosa*, *Kulfi*).
* **Desi Nostalgia & College Life:** Everyday campus memories and childhood classics (*Gullidanda*, *Antakshari*, *Shaktimaan*, *Malgudi*, *Canteen*, *Chai*, *Ludo*, *Tuition*, *Proxy*, *Jugaad*).
* **Custom Word:** Pass-and-play mode where Player 1 enters a secret word (2–20 letters) and up to 3 custom hints.

---

## ⚡ Scoring & Power-Ups

| Mechanic / Power-Up | Shortcut | Cost / Reward | Effect |
| :--- | :---: | :---: | :--- |
| **Correct Letter** | `A–Z` | `+100 × Streak` | Reveals matching tiles and increases your combo multiplier. |
| **Wrong Letter** | `A–Z` | `-1 Life` | Resets your current streak to `0x` and draws the next hangman segment. |
| **Round Win Bonus** | — | `+20 × Lives Left` | Rewards unused hearts at the end of a solved word. |
| **Extra Hint** | Click | `150 pts` / `250 pts` | Unlocks Hint 2 and Hint 3 progressively. |
| **50/50** | Click | `200 pts` | Eliminates half of the remaining incorrect letters on the keyboard. |
| **Buy a Letter** | `?` | `300 pts` | Automatically reveals one unguessed letter in the word. |
| **All-In Guess** | `!` | `+500 pts` / Instant Loss | Type the full word at once. Right wins `+500 pts`; wrong loses the round immediately. |

---

## 🔊 Dynamic Desi Audio Engine

Built using the browser's **Web Audio API** and **SpeechSynthesis API** with zero external `.mp3` dependencies:

* **Bollywood:** Snappy tabla beats, Bollywood brass riffs, and celebratory dialogues on wins; the dramatic 3-hit *"Dhoom-Tan-Na-Na"* soap-opera sting with a **triple white screen flash** on losses.
* **Cricket:** Bat-on-ball leather crack, stadium crowd roar, and a 4/6 boundary horn on wins; bail rattle, umpire whistle, and crowd *"AWWW!"* groan on losses.
* **Street Food:** Crunchy golgappa crackle and vendor bell chime on wins; hot tawa sizzle and a cartoon *"Mirchi lag gayi!"* slide-whistle drop on losses.
* **Desi Nostalgia & College Life:** Retro 8-bit Doordarshan TV chime and canteen cup clinks on wins; a loud *"TRINGGG!"* lecture bell and low trombone *"wah-wah"* on losses.

---

## 🚀 Running Locally

1. Download or clone the repository.
2. Open the `.html` file directly in any modern web browser (Chrome, Edge, Firefox, or Safari)—no build tools, servers, or external audio files required.
