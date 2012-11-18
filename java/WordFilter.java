import java.util.List;
public class WordFilter {
	
	private FSM fsm ;
	public WordFilter()
	{
		fsm = new FSM();
	}
	public void initFilterWithWords(List<String> words)
	{
		fsm.init(words);
	}
	public  String applyFilter(String src)
	{
		char [] str = src.toCharArray() ;
		FSM.State curState = fsm.begin();
		for(int index = 0 ; index < str.length  ; )
		{	
			curState = fsm.nextState(curState,Utils.toLowercase(str[index]));
			if(fsm.isEnd(curState))
			{			
				String match = fsm.getMatch(curState) ;
				for(int i = 0  ; i < match.length() ; i++)
				{
					str[index - i ] = '*' ;
				}
			}		
			index ++ ;
		}
		return new String(str);
	}
}
