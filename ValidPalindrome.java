package greedy;

public class ValidPalindrome {
	public boolean validPalindrome(String s) {
        int len = s.length();
        int head = 0, tail = len-1;
        boolean flag = true;//默认就是回文的
        //找到不匹配处
        while(s.charAt(head) == s.charAt(tail) && head<tail) {
        	head++;
        	tail--;
        }
        /**发现不匹配情况*/
        if(head < tail) {//处理这个不符合条件的字符对
        	flag = false;
        	if(s.charAt(head+1) == s.charAt(tail))
        		head += 1;
        	else if(s.charAt(tail-1) == s.charAt(head))
        		tail -= 1;    	
        }
        else
        	return true;
        /**处理完不匹配情况后的再次判断*/
        for(;head < tail; head++,tail--) {
    //		System.out.println(s.charAt(head));
        	if(s.charAt(head) != s.charAt(tail))
        		return false;//再次发现不符合情况
        }
        return true;//字符串本就是回文序列   	
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
		String s2 = "aguokepatgbnvfqmgmlucupuufxoohdfpgjdmysgvhmvffcnqxjjxqncf";//为将后半部分的字符串转置引入t,此为翻转后的结果。
		/**
		System.out.println(s.length());101
		System.out.println("s1 "+s1.length());56
		System.out.println("t "+t.length());57  显然根据该串的匹配特点，是需要删除一个元素的
		StringBuffer t = new StringBuffer("fcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
		System.out.println(t.reverse());
		*/

		System.out.println(s1.compareTo(s2));
		//在aguokepatgbnvfqmgml的下个位置出现不等。如何删除的两个条件都满足但只有走else那条才能完成匹配，但if匹配后直接程序向后运行并为给else机会，从而与真相擦肩而过！
		ValidPalindrome test = new ValidPalindrome();
		System.out.println(test.validPalindrome(s));
		//System.out.println(test.validPalindrome(t));
	}
	//针对这个思维漏洞，对于必要处理的情况如发现不匹配的情况要处理，我们设计出的处理方案应该是完备的；则设计的if-else要是对立事件
	//显然真实情况存在：既满足if又满足else，那就应该反思这种情况对结果有无影响，因会先走if分支然后结束程序。
	//当结果可能存在于else时，显然这种if-else的线性逻辑不可行。应该赋予else同样的试错机会，学习answer种的答案

}
