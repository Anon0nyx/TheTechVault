#include <iostream>
#include <memory>

using namespace std;

int smort_pointer() {
  unique_ptr<int> uptr(new int(24)); // STUPID STUPID STUPID!!!! I HATE SMORT POINTERS
  cout << "DUMBO UNIQUE POINTER VALUE: " << *uptr << endl;

  shared_ptr<int> sptr1(new int(24)); // WHAT THE FUCK IS A SHARED POINTER I HATE YOU
  shared_ptr<int> sptr2 = sptr1; // WOAH SHARED OWNERSHIP???? WOOOOO
  cout << "Shared ptr val: " << *sptr1 << endl;
  cout << "Shared ptr use count: " << sptr1.use_count() << endl; // YEAH I FUCKING LOVE (HATE) SNAKE CASE AND BEING FORCED TO USE IT!!!!

  // alright boys thank you for cleaning up the memory, time to exit this scope 
  // WOO NO CLEANUP!! WOOO
  return 0;
}

int main() {
  smort_pointer();

  return 0;
}


/*
Alright, less hate, more learning...
  unique_ptr<int> uptr(new int(24)); // a unique pointer can only manage one resource at a time, meaning only uptr can access this value
  cout << "Unique pointer value: " << *uptr << endl; // to transfer ownership of uptr somewhere else... do this below
  unique_ptr<int> better_uptr = move(uptr); // uptr's gf has officially moved onto better_uptr and he now owns that value, uptr is now = NULL :*(

  shared_ptr<int> sptr1(new int(24)); // Shared pointers allow multiple variables/pointers to share the ownership over the address and value
  shared_ptr<int> sptr2 = sptr1; // polyamory is fuckin gross but in programming it actually makes sense for sptr1 to share his value with sptr2
  cout << "Shared ptr val: " << *sptr1 << endl;
  cout << "Shared ptr use count: " << sptr1.use_count() << endl; // :'(

  Notes:
  For real though smart pointers kind of fucking suck and its genuinely more likely that 
  cleaning up after yourself, assuming you arent dull, is more efficient than using "smart" pointersX
*/