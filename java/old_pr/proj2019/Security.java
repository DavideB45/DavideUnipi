final public class Security{
	
	private String _passw;
	private Vector<String> friends;
	
	public Security(String passw) throws NullPointerException{
		if(passw == null){
			throw NullPointerException();
		}
		this._passw = passw;
		friends = null;
	}

	public boolean add_friend(String passw, string friend) throws NullPointerException{
		if(passw == null || friend == null){
			throw NullPointerException();
		}
		boolean result = 0;
		if(_passw.equals(passw)){
			//inserzione ordinata
			int i = 0, s = friends.size();
			while(i <= s){
				if(friends.get(i).compareTo(friend) > 0){
					i++;
				} else {
					friends.add(i, friend);
					break;
				}
			}
			result = 1;
		}
		return result;
	}
}