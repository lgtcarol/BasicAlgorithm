package greedy;

public class ValidPalindrome {
	public boolean validPalindrome(String s) {
        int len = s.length();
        int head = 0, tail = len-1;
        boolean flag = true;//Ĭ�Ͼ��ǻ��ĵ�
        //�ҵ���ƥ�䴦
        while(s.charAt(head) == s.charAt(tail) && head<tail) {
        	head++;
        	tail--;
        }
        /**���ֲ�ƥ�����*/
        if(head < tail) {//��������������������ַ���
        	flag = false;
        	if(s.charAt(head+1) == s.charAt(tail))
        		head += 1;
        	else if(s.charAt(tail-1) == s.charAt(head))
        		tail -= 1;    	
        }
        else
        	return true;
        /**�����겻ƥ���������ٴ��ж�*/
        for(;head < tail; head++,tail--) {
    //		System.out.println(s.charAt(head));
        	if(s.charAt(head) != s.charAt(tail))
        		return false;//�ٴη��ֲ��������
        }
        return true;//�ַ��������ǻ�������   	
    }
/**
	private boolean isPalindrome(String s, int l, int r) {
		while(l < r) {
			if(s.charAt(l) != s.charAt(r))
				return false;
			l++;
			r--;
		}
		return true;
	}
*/
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
		String s1 = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncf";
		String s2 = "aguokepatgbnvfqmgmlucupuufxoohdfpgjdmysgvhmvffcnqxjjxqncf";//Ϊ����벿�ֵ��ַ���ת������t,��Ϊ��ת��Ľ����
		/**
		System.out.println(s.length());101
		System.out.println("s1 "+s1.length());56
		System.out.println("t "+t.length());57  ��Ȼ���ݸô���ƥ���ص㣬����Ҫɾ��һ��Ԫ�ص�
		StringBuffer t = new StringBuffer("fcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
		System.out.println(t.reverse());
		*/

		System.out.println(s1.compareTo(s2));
		//��aguokepatgbnvfqmgml���¸�λ�ó��ֲ��ȡ����ɾ�����������������㵫ֻ����else�����������ƥ�䣬��ifƥ���ֱ�ӳ���������в�Ϊ��else���ᣬ�Ӷ���������������
		ValidPalindrome test = new ValidPalindrome();
		System.out.println(test.validPalindrome(s));
		//System.out.println(test.validPalindrome(t));
	}
	//������˼ά©�������ڱ�Ҫ���������緢�ֲ�ƥ������Ҫ����������Ƴ��Ĵ�����Ӧ�����걸�ģ�����Ƶ�if-elseҪ�Ƕ����¼�
	//��Ȼ��ʵ������ڣ�������if������else���Ǿ�Ӧ�÷�˼��������Խ������Ӱ�죬�������if��֧Ȼ���������
	//��������ܴ�����elseʱ����Ȼ����if-else�������߼������С�Ӧ�ø���elseͬ�����Դ���ᣬѧϰanswer�ֵĴ�

}
