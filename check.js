var foo_module = require('./build/foo.js');

var huj = 0;

var add_two_numbers_runtime = foo_module.Runtime.addFunction(function add_two_numbers(a, b) {
	console.log('Hello from JS!');
	console.log('a', a);
	console.log('b', b);
	huj++;
	return a - b;
});

var callbacks = foo_module._foo_new_callbacks(add_two_numbers_runtime);
var foo = foo_module._new_foo();
console.log('foo is', foo);
foo_module._foo_set_callbacks(foo, callbacks);

console.log('internal value BEFORE', foo_module._foo_get_internal_value(foo));

var result = foo_module._foo_add(foo, 10, 20);
console.log('add result is', result);
console.log('internal value AFTER', foo_module._foo_get_internal_value(foo));
foo_module._free_foo(foo);
foo_module._foo_free_callbacks(callbacks);
console.log(huj);