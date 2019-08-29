<?php

namespace Rector\Doctrine\Tests\Rector\Class_\AddUuidToEntityWhereMissingRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 */
class SomeEntityWithIntegerId
{
    /**
     * @var int
     * @ORM\Id
     * @ORM\Column(type="integer")
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;
}

?>
-----
<?php

namespace Rector\Doctrine\Tests\Rector\Class_\AddUuidToEntityWhereMissingRector\Fixture;

use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 */
class SomeEntityWithIntegerId
{
    public function __construct()
    {
        $this->uuid = \Ramsey\Uuid\Uuid::uuid4();
    }
    /**
     * @var \Ramsey\Uuid\UuidInterface
     * @ORM\Column (type="uuid_binary", unique=true, nullable=true)
     */
    private $uuid;
    /**
     * @var int
     * @ORM\Id
     * @ORM\Column(type="integer")
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;
}

?>