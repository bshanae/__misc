namespace						Computor
{
	public class				Element
	{
		public Holder			Holder;
		
		public bool				HasHolder => Holder == null;

		public void				ConnectHolder(Holder newHolder)
		{
			Holder?.DisconnectElement();
			newHolder.ConnectElement(this);
		}
		
		public Holder			DisconnectHolder()
		{
			Holder				oldHolder = Holder;
			
			Holder.DisconnectElement();
			return oldHolder;
		}
	}
}