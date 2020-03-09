using System;

class streams
{
    public class IntStream
    {
        protected int num;
        public IntStream()
        {
            this.num = 0;
        }
        public virtual void reset()
        {
            this.num = 0;
        }
        virtual public int next()
        {
            int actual = this.num;
            this.num++;
            return actual;
        }
        public virtual bool eos()
        {
            if(this.num > int.MaxValue-1)
            {
                return true;
            }
            return false;
        }
    }

    public class PrimeStream : IntStream
    {
        public PrimeStream()
        {
            base.num = 2;
        }

        public override void reset()
        {
            base.num = 2;
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
        public override int next()
        {
            int actual = base.num;
            do
            {
                base.num++;
            }while(!isPrime(base.num) && !base.eos());
            return actual;
        }
    }

    public class RandomStream : IntStream
    {
        private static Random rnd;

        public RandomStream()
        {
            rnd = new Random();
        }
        public override int next()
        {
            return rnd.Next(32, 126);
        }
        public override bool eos()
        {
            return false;
        }
    }

    public class RandomWordStream
    {
        private RandomStream rs;
        private PrimeStream ps;

        public RandomWordStream()
        {
            rs = new RandomStream();
            ps = new PrimeStream();
        }
        public string next()
        {
            if(ps.eos())
            {
                return "Prime Stream finished please reset";
            }
            int len = ps.next();
            char[] array = new char[len];
            for(int i = 0; i < len; i++)
            {
                array[i] = (char)rs.next(); 
            }
            string ret = new string(array);
            return ret; 
        }
        public void reset()
        {
            ps.reset();
        }
    }
    public static void Main()
    {
        RandomWordStream instrea = new RandomWordStream();
        for(int i = 0; i < 10; i++)
        {
            Console.WriteLine(instrea.next());
        }
        Console.WriteLine(instrea.next());
        instrea.reset();
        for(int i = 0; i < 10; i++)
        {
            Console.WriteLine(instrea.next());
        }
    }
}