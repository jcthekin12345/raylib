

/*As you move through the village of Enumerant, you notice a short, cloaked figure following you. Not
   being one to enjoy a mysterious figure tailing you, you seize a moment to confront the figure. “Don’t be
   alarmed!” she says. “I am Simula. They are saying you’re a Programmer. Is this true?” You answer in the
   affirmative, and Simula’s eyes widen. “If you are truly a Programmer, you will be able to help me. Follow
   me.” She leads you to a backstreet and into a dimly lit hovel. She hands you a small, locked chest. “We
   haven’t seen any Programmers in these lands in a long time. And especially not ones that can craft types.
   If you are a True Programmer, you will want what is in that chest. And if you are a True Programmer, I
   will gladly give it to you to aid you in your quest.”*/


/*The chest is a small box you can hold in your hand. The lid can be open, closed (but unlocked), or locked.
You’d normally be able to go between these states, opening, closing, locking, and unlocking the box, but
the box is broken.You need to create a program with an enumeration to recreate this locking mechanism.
The image below shows how you can move between the three states:*/

namespace SimulasTest
{
    internal class Program
    {
        enum LockStates { Open, Closed, Unlock, Locked };
        static void Box()
        {

            LockStates state = LockStates.Locked;
            while (true)
            {
                if (state == LockStates.Closed)
                {
                    Console.WriteLine("The Chest is Locked. What do you wanna do?: ");
                    state = LockStates.Open;
                    string? userInput = Console.ReadLine();
                    if (userInput != null)
                    {
                        throw new Exception("DIDN'T ENTER ANYTHING!!!");
                    }
                    else
                    {
                        
                    }
                }
            }
        }

        static void Main(string[] args)
        {

        }
    }
}
