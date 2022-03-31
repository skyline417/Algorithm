import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        String temp=scanner.next();
        int length=temp.length();
        TreeMap<Character,Integer> hashMap=new TreeMap<>();
        for(int i=0;i<length;i++){
            char c=temp.charAt(i);
            int num=1;
            if(hashMap.containsKey(c)){
                num+=hashMap.get(c);
            }
            hashMap.put(c,num);
        }
        String r="",rr="";
            TreeMap<Character,Integer> hashMap1=new TreeMap<>();
            Iterator iterator=hashMap.entrySet().iterator();
            int max=0;
            while(iterator.hasNext()){
                Map.Entry entry=(Map.Entry) iterator.next();
                char c=(char) entry.getKey();
                int i=(int) entry.getValue();
                if(i%2!=0){
                    continue;
                }
                if((i<4||i%4!=0)){
                    if(i>max){
                        max=i;
                        hashMap1.clear();
                        hashMap1.put(c,i);
                    }else if(i==max){
                        hashMap1.put(c,i);
                    }
                }else{
                    for(int j=0;j<i/4;j++){
                        r+=c;
                    }
                }
            }
            rr=r;
            if(!hashMap1.isEmpty()){
                Iterator iterator1=hashMap1.entrySet().iterator();
                Map.Entry entry=(Map.Entry) iterator1.next();
                char c=(char) entry.getKey();
                int i=(int) entry.getValue();
                for(int k=0;k<i/2;k++){
                    rr+=c;
                }
            }
            for(int i=r.length()-1;i>=0;i--){
                rr+=r.charAt(i);
            }
            rr+=rr;
            if(rr==""){
                System.out.println("N/A");
                return;
            }
        System.out.println(rr);
    }
}