using System.Collections.Generic;
using CommandLine;
using System.Linq;

public static partial class			Program
{
	public static class				Options
	{
		private class 				Sample
		{
			public					Sample
									(
										bool report,
										bool treeView,
										bool forcePattern,
										bool debug,
										bool test
									)
			{
				Report = report;
				TreeView = treeView;
				ForcePattern = forcePattern;
				Debug = debug;
				Test = test;
			}

			[Option("report", Default = false)]
			public bool				Report { get; }
		
			[Option("treeView", Default = false)]
			public bool				TreeView { get; }
			
			[Option("forcePattern", Default = false)]
			public bool				ForcePattern { get; }
			
			[Option("debug", Default = false)]
			public bool				Debug { get; }
			
			[Option("test", Default = false)]
			public bool				Test { get; }
		}
		
		public static bool			Report { get ; private set ; }
		public static bool			TreeView { get ; private set ; }
		public static bool			ForcePattern { get; private set; }
		
		public static bool			Debug { get ; private set ; }
		public static bool			Test { get ; set ; }

		static						Options()
		{
			Report = true;
			TreeView = false;
			ForcePattern = false;
			Debug = false;
			Test = false;
		}

		public static void			Parse()
		{
			CommandLine.Parser		parser;

			parser = new Parser(config =>
			{
				config.CaseSensitive = false;
				config.HelpWriter = null;
				config.IgnoreUnknownArguments = false;
			});

			parser
				.ParseArguments<Sample>(Workspace.CommandLineArguments)
				.WithParsed(ProcessParsed)
				.WithNotParsed(ProcessNotParsed);

			static void				ProcessParsed(Sample sample)
			{
				Report = sample.Report;
				TreeView = sample.TreeView;
				ForcePattern = sample.ForcePattern;
				Debug = sample.Debug;
				Test = sample.Test;
			}

			static void				ProcessNotParsed(IEnumerable<CommandLine.Error> errors)
			{
				if (errors.Any())
					Error.RaiseUsageError(Error.UsageErrors.InvalidCommandLineArguments);
			}
		}
	}
}