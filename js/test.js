const data = require('../output/dom.json');

const printNestedObject = (object) => {
	console.log(object);
	if (object.child) {
		printNestedObject(object.child);
	}
}

printNestedObject(data);
