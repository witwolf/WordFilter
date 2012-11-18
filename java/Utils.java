

public class Utils {
	public static char toLowercase(char input)
	{
		if(input > 65 && input < 90)
			return (char) (input + 32) ;
		return input ;
	}

}
