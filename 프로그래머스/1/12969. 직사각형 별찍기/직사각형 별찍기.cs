using System;

public class Example
{
    public static void Main()
    {
        String[] s;
        Console.Clear();
        s = Console.ReadLine().Split(' ');
        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);
        for(int h = 0; h < b; h++){
            for(int w = 0; w < a; w++){
                Console.Write('*');
            }
            Console.Write('\n');
        }
        return;
    }
}