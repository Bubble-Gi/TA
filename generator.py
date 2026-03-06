import random
from xeger import Xeger

def generate_mixed_data(regex, total_count, bad_ratio = 0.3):
    x = Xeger()
    result = []

    for _ in range(total_count):
        is_bad = random.random() < bad_ratio
        valid_string = x.xeger(regex)

        if is_bad:
            mutation_type = random.choice(['insert', 'delete', 'replace', 'case'])

            if mutation_type == 'insert':
                char = random.choice('() _.1234567890')
                idx = random.randint(0, len(valid_string))
                mutated = valid_string[:idx] + char + valid_string[idx:]

            elif mutation_type == 'delete' and len(valid_string) > 1:
                idx = random.randint(0, len(valid_string) - 1)
                mutated = valid_string[:idx] + valid_string[idx+1:]

            elif mutation_type == 'replace':
                idx = random.randint(0, len(valid_string))
                char = random.choice('() _.1234567890')
                mutated = valid_string[:idx] + char + valid_string[idx+1:]

            else:
                mutated = valid_string.swapcase()
            result.append(mutated)
        else:
            result.append(valid_string)

    return result

my_regex = (r'(^create ([a-zA-Z][\w.]*) \( ([a-zA-Z][\w.]*(?:,[a-zA-Z][\w.]*)*) \)$)|(^create ([a-zA-Z][\w.]*) as ([a-zA-Z][\w.]*) join ([a-zA-Z][\w.]*)$)')
data = generate_mixed_data(my_regex, total_count=1000000, bad_ratio=0.5)
with open('cmake-build-debug/100.txt', 'w', encoding='utf-8') as f:
    for string in data:
        f.write(f"{string}\n")
