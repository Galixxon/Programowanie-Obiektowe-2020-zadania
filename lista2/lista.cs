using System;
using System.Collections.Generic;
class lista
{
    public class ListaLeniwa
    {
        protected int size;
        private Random random;
        protected List<int> lista;

        public ListaLeniwa()
        {
            size = 0;
            random = new Random();
            lista = new List<int>();

        }
        public virtual int element(int i)
        {
            if(i < size)
            {
                return lista[i-1];
            }
            else
            {
                for(int j = size; j < i; j++)
                {
                    lista.Add(random.Next());
                }
                size = i;
                return lista[i-1];
            }
        }
    }

    class Pierwsze : ListaLeniwa
    {
        private int actualPrime;
        public Pierwsze() : base()
        {
            actualPrime = 1;
        }

        private int nextPrime()
        {
            do
            {
                actualPrime++;
            }while(!isPrime(actualPrime));
            return actualPrime;
        }
        private bool isPrime(int a)
        {
            int sqr = (int)Math.Floor(Math.Sqrt(a));
            for(int i = 2; i <= sqr; i++)
            {
                if(a%i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        public override int element(int i)
        {
            if(i < size)
            {
                return lista[i-1];
            }
            else
            {
                for(int j = size; j < i; j++)
                {
                    lista.Add(nextPrime());
                }
                size = i;
                return lista[i-1];
            }
        }
    }
    class Program
    {
        public static void Main()
        {
            ListaLeniwa lista = new ListaLeniwa();
            for(int i = 1; i < 11; i++)
            {
                Console.WriteLine(lista.element(i));
            }
            Console.WriteLine("\n");
            for(int i = 1; i < 11; i+=2)
            {
                Console.WriteLine(lista.element(i));
            }


            Pierwsze ll = new Pierwsze();
            for(int i = 1; i < 11; i++)
            {
                Console.WriteLine(ll.element(i));
            }
            Console.WriteLine("\n");
            for(int i = 1; i < 11; i+=2)
            {
                Console.WriteLine(ll.element(i));
            }

            Console.WriteLine(ll.element(35));

            Console.WriteLine(ll.element(14));
        }
    }
}