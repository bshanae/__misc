using NUnit.Framework;

namespace						Computor
{
	public class				Element
	{
		public Holder			Holder
		{
			get;
			private set;
		}

		public void				Place(Holder holder)
		{
			Error.Assert(Holder == null);
			
			Holder = holder;
			holder.Element = this;
		}
		
		public void				Replace(Holder newHolder)
		{
			Error.Assert(Holder != null);
			
			Holder.Element = null;
			Holder = newHolder;
			newHolder.Element = this;
		}
		
		public void				Replace(Element newElement)
		{
			Error.Assert(Holder != null);
			
			Holder.Element = null;
			Holder.Element = newElement;
		}

		public Holder			Drop()
		{
			Holder				holder = Holder;
			
			Holder.Drop();
			Holder = null;

			return holder;
		}
	}
}