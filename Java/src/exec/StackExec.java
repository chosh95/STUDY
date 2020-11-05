package exec;

import java.util.Objects;
import java.util.Stack;

public class StackExec {
    static class Stack<T>{
        public T[] p;
        int Idx;
        int stackSize;

        public Stack(int size) {
            Idx = -1;
            stackSize = size;
            p = (T[])new Object[size];
        }

        public boolean isEmpty(){
            return (Idx == -1);
        }

        public boolean isFull(){
            return (Idx==stackSize-1);
        }

        public void push(T data){
            if(Idx==stackSize)
                return;
            p[++Idx] = data;
        }

        public T peek(){
            if(!isEmpty())
                return p[Idx];
            return null;
        }

        public T pop(){
            if(!isEmpty()){
              return p[Idx--];
            }
            return null;
        }

        public void clear(){
            p = (T[])new Object[p.length];
        }
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>(10);
        System.out.println(s.isEmpty());
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        System.out.println(s.isFull());
        System.out.println(s.isEmpty());
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
    }
}
