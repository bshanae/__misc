package org.bshanae.fixMe.market.transaction;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

import java.util.List;

public class							TransactionHistory
{
	private final SessionFactory		sessionFactory;

	private Session						session;
	private org.hibernate.Transaction	transaction;
	private int							lastTransactionId;

	public 								TransactionHistory()
	{
		 sessionFactory = new Configuration().configure().buildSessionFactory();

		 lastTransactionId = -1;
		 for (Transaction transaction : getAll())
		 	lastTransactionId = Math.max(lastTransactionId, transaction.getId());
	}

	public Transaction[]				getAll()
	{
		Query							query;
		List<?>							transactions;

		beginTransaction();
		query = session.createQuery("FROM Transaction");
		transactions = query.list();

		return transactions.toArray(new Transaction[0]);
	}

	public void							put(Transaction transaction)
	{
		transaction.setId(++lastTransactionId);

		beginTransaction();
		session.save(transaction);
		endTransaction();
	}

	public void 						clear()
	{
		beginTransaction();
		session.createQuery("DELETE FROM Transaction").executeUpdate();
		endTransaction();
	}

	private void						beginTransaction()
	{
		session = sessionFactory.openSession();
		transaction = session.beginTransaction();
	}

	private void						endTransaction()
	{
		transaction.commit();
		session.close();
	}
}
