namespace RepairingClock
{
    internal class Program
    {
        public static void Clock(int num)
        {
            if (num < 0)
            {
                throw new ArgumentException("Number must be a non-negative integer.");
            }
            else if ((num % 2) == 0)
            {
                Console.WriteLine("Tick");
            }
            else
            {
                Console.WriteLine("Tock");
            }

        }
        static void Main(string[] args)
        {
            for (int i = 0; i < 60; ++i)
            {
                Clock(i);
                Thread.Sleep(1000);
            }
        }
    }
}
