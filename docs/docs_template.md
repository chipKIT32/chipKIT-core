---
layout: default
title: How to add documentation to the docs folder
---

    <!-- START OF DOCUMENTATION, DO NOT ALTER LINES ABOVE THIS POINT (UNLESS YOU HAVE A REALLY GOOD REASON) -->
		
	## Formatting Documents
	
	All documents need to have something called YAML front matter. This is a section at the beginning of your document which starte with three dashes and ends with three dashes. In between these dashes you can specify the layout template you wish to use as well as the page title. The YAML is processed by a Jekyll engine by github. Here is an example:
	
	<pre>
	---
	layout: default
	title: How to add documentation to the docs folder
	---
	</pre>
	
	## Adding Documents	
	
	Add the document to the /docs folder in either HTML or Markdown (md) format. Note that HTML documents should not contain the HTML, Header, or Body tags since the documents contents will ultimately be inserted in a template which already contains these items.
	
	## Update the Navigation Menu
	
	In the _data folder you will find the nav.yml file. Update this file to add a link to your file.
	
    <!-- END OF DOCUMENTATION, DO NOT ALTER LINES BELOW THIS POINT (UNLESS YOU HAVE A REALLY GOOD REASON) -->
