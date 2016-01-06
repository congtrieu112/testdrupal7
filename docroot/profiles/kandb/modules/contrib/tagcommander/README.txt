CONTENTS OF THIS FILE
---------------------
* Introduction
* Requirements
* Installation
* Configuration
* Troubleshooting
* FAQ
* Maintainers

INTRODUCTION
------------
The TagCommander module for Drupal allows TagCommander clients to implement and manage TagCommander quickly and easily without technical knowledge. With TagCommander module, clients through Drupal configuration interface are able to manage their datalayer and container(s). All the variables of the datalayer are retrieved from TagCommander configured site and can be populated with Drupal variables values or custom variables values. The purpose of this README file is to help clients to implement and manage TagCommander through the module.

REQUIREMENTS
------------
This module requires no others modules. You have only to be TagCommander client (contact us on http://wwww.tagcommander.com if you're interested).

INSTALLATION
------------
Install as usual, see https://drupal.org/documentation/install/modules-themes/modules-7 for further information.

CONFIGURATION
-------------

* Step 1: activate the TagCommander modules

When your IT team will have finished the installation, sign in to Drupal as an administrator and go to “Modules > TAGCOMMANDER”. Activate the two TagCommander modules by checking the checkbox and clicking on “Save configuration” button.

* Step 2: configure your TagCommander account

Go in “Configuration > TAGCOMMANDER > Account Settings” and enter your TagCommander credentials. When it will be done, click on “Login” button and choose behind the website from which retrieve the datalayer. All the variables created in TagCommander through “Container options > External variables Repository” interface will be retrieved and automatically displayed in the next step.

* Step 3: create your datalayer

Go in “Configuration > TAGCOMMANDER > Datalayer configuration”. You should see all the datalayer variables of the TagCommander site selected at step 2. The purpose of this interface is to populate the datalayer with the needed Drupal variable value. You can for each datalayer variable select the drupal variable to use for the populating. On the click on the “Save” button, the linking between the datalayer and the Drupal variables will be saved and the datalayer will be automatically added to all your website pages. The “Reload” button will retrieve all the datalayer variables from the website selected. Be careful with the use of the “Reload” button because all the variables will be retrieve but the linking between the datalayer and the Drupal variables configured will be lost. The Drupal variables are displayed and categorized in a dropdown list.

Here are the possible categories:

Categories	        Description
Default variables	Native Drupal variables
Article			Variables linked to the content type article (if there is a content type article)
Page			Variables linked to the content type page (if there is a content type page)
Others 			content types	All the variables of others content type will be displayed here
Custom			Custom variables configured by your IT team (optional)

Once the datalayer creation will be finished, you will be able to add your container(s) at step 4.

* Step 4: add your container(s)

Go in “Configuration > TAGCOMMANDER > Container(s) configuration”. Click on the “Add container” button and fill the form. Firstly, you select the container from the site selected at step 2. Then, you choose the position of the container between header and footer. Normally if your container doesn’t contain any A/B testing tag, you should choose the footer position. If you have any doubt contact the support team or your TagCommander consultant. In the fied “Url”, enter the url of your container (example: http://cdn.tagcommander.com/18/tc_TCWebsites_17.js).

* Advanced: populate the datalayer with custom values

If you want to populate your datalayer using variables that are not listed in the dropdown Drupal variables list, you can do it by asking your IT team to add them. Marketing team will have to provide to IT team for each variable wanted:

- Name of the variable (this is this name that will appear in the Drupal back-office)
- Description of the value (example: user ID from the CRM etc.)
- Several examples of values (example: “154544”, “5674664” etc.)

Then, IT team will need to edit the module file “custom_variables” located in the folder “custom_variables”. In “custom_variables_tagcommander_variables” function, IT team have to define the name of the variable as your marketing team wants to see in the Drupal Back office. In “custom_variables_preprocess_variable_value” function, IT team have to define the value of the custom variable. When the IT team will have finished, you will see in the dropdown Drupal variables list the new variables created and you will be able to use them to populate datalayer variables.

TROUBLESHOOTING / FAQ
---------------------
Please contact the TagCommander support team for any questions: support@tagcommander.com .

MAINTAINERS
-----------
Current maintainers:
* TagCommander 
