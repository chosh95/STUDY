package exec;

public class CastringEx {

    static class Parent{
        void print(){
            System.out.println("parent");
        }
    }
    static class Child extends Parent{
        @Override
        void print() {
            System.out.println("child");
        }
        void print2(){
            System.out.println("child 2");
        }
    }
    public static void main(String[] args) {
        Parent p = new Child(); // 업 캐스팅 (Parent) 생략 묵시적 형변환
        p.print(); // child 출력
        //p.print2();  오류
        
        Child newChild = (Child) p;
        newChild.print2(); // 선행된 업 캐스팅으로 다운 캐스팅이 가능.

        Child c = (Child)new Parent(); // 다운 캐스팅 : 런타임 오류(ClassCastException)
        c.print();
    }
}
