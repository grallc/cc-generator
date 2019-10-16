#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string generateCreditCardNumber() {
  int randomNumber = rand() % (9 + 1);
  return to_string(randomNumber);
}

bool checkCreditCard(string creditCardNumber) {
  int even = 0;
  int odd = 0;
  int counter = 1;
  for (int x = creditCardNumber.length() - 1; x >= 0; x--) {
    char a = creditCardNumber.at(x);
    int newNumber = (a - '0');

    if (counter % 2 == 0) {
      newNumber = 2 * newNumber;
      if (newNumber > 9) newNumber = newNumber - 9;
      even += newNumber;
    } else {
      odd += newNumber;
    }
    counter++;
  }
  return (even + odd) % 10 == 0;
}

int main(int ac, char *argv[]) {
  int attempts = 0;
  int askedAttempts = 0;
  if (ac > 1) {
    try {
      askedAttempts = stoi(argv[1]);
    } catch (const invalid_argument &error) {
      cout << "That does'nt seem to be a correct number 🧐";
      return (1);
    }
  } else {
    askedAttempts = 1000;
  }

  if(askedAttempts > 10000) {
    cout << "Not a good idea. Trust me. 🚶" << endl;
    return (1);
  }

  vector<string> validCreditCards;
  while (attempts < askedAttempts) {
    string cardNumber;
    attempts++;
    for (int x = 1; x <= 16; x++) {
      cardNumber = cardNumber + generateCreditCardNumber();
    }
    if (checkCreditCard(cardNumber)) {
      validCreditCards.push_back(cardNumber);
      cout << cardNumber
           << " is a valid Credit Card number. It has been found after "
           << attempts << " attempt(s)" << endl;
    }
  }
  cout << endl
       << "Generating a credit card is actually wayyy easier I was thinking. "
       << endl
       << "We generated "
       << validCreditCards.size() << " valid credit cards in " << attempts
       << " attempt(s) ! 🤨" << endl;
  cout << "Thanks for looking at this useless project ! 🤪" << endl;
  return 0;
}