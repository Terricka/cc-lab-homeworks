//place to save tasks
var taskArray = [];
var taskDeleted;

function normalColor() {
  document.body.style.backgroundColor = "#FFFFFF";
  console.log('normal');
  document.getElementById('taskResponse').innerHTML = '';
};
	
var timeout;
function deleteColor() {
  timeout = window.setTimeout(normalColor, 1500);
  
};

function urgentTask() {
	

};

var taskResponse = function(){
	
	if (newTask) {
		document.getElementById('taskResponse').innerHTML = '<p>New task added</p>'; // added in
	};
	
	document.body.style.backgroundColor = "#7AD4B7";
	console.log('green');
	deleteColor();
	
	

};

var taskDeleted = function(){
	if (deleteTask) {
		document.getElementById('taskResponse').innerHTML = '<p>Task Deleted</p>'; // added in
	};
	
	document.body.style.backgroundColor = "#e74d4d";
	console.log('red');
	deleteColor();
	
};

//delete task
var deleteTask = function(e){
	var taskNumber = e.target.parentElement.id; //gets element id that's being removed
	taskArray.splice(taskNumber, 1); //2 parameters, where it wants to be spliced and for how long (once)
	taskDeleted();
	updateTasks();
};

//update task list
var updateTasks = function(){
	var taskListHolding = document.getElementById('taskList'); // defines the last task list div


	// empty the task list

	taskListHolding.innerHTML = " "; // empties html for this element

	var len = taskArray.length; // get length of array
	var i;

	for (i = 0; i < len; i++) { // for loop for the tasks in the array. runs for each new update
		console.log('task ' + i + ": " + taskArray[i]);

		var newTask = document.createElement('div'); // creating a div for the new tasks

		newTask.id = i; // define the div's id 
		newTask.className = 'task'; // gives new class name to div created for newTask variable
		// creating task paragraph element

		var task = document.createElement('p');

		task.innerHTML = taskArray[i]; // the inner html equals whatever was listed in the taskArray array

		var deleteButton = document.createElement('button'); // creates delete button for each task [i]
		deleteButton.id = "deleteButton";  // gives delete button an id

		deleteButton.innerText="x"; // gives inner text of 'X' for close
		deleteButton.addEventListener('click',function(e){  //listens for click on delete button
			e.preventDefault();
			deleteTask(e);
		});

		// adds new tasks (append does this)
		newTask.appendChild(task);

		// adds delete button to new task
		newTask.appendChild(deleteButton);


		// appends the taskDiv to the taskHolding Div
		taskListHolding.appendChild(newTask);

	};	
};

//save task
var saveTask = function(){
	var taskInput = document.getElementById('newTask'); // gets input element html entry
	var newTask = taskInput.value; // makes newTask equal to the input of taskInput
	taskArray.push(newTask); // add new value to your array

updateTasks(); // runs update tasks function


taskInput.value="";
console.log(taskArray);
	
};



//init
var init = function(){
	 var addButton = document.getElementById('addButton');  /// get addButton element
   
  //add event listener for click
  addButton.addEventListener('click',function(e){  // add event Listener for click
    e.preventDefault();  // prevent new page loading
    saveTask();  // runs save task function
    taskResponse();
  });
 };

window.onload = init();